#!/usr/bin/env python3

###
# Generates build files for the project.
# This file also includes the project configuration,
# such as compiler flags and the object matching status.
#
# Usage:
#   python3 configure.py
#   ninja
#
# Append --help to see available options.
###

import argparse
import sys
from pathlib import Path
from typing import Any, Dict, List

from tools.project import (
    Object,
    ProjectConfig,
    calculate_progress,
    generate_build,
    is_windows,
)

# Game versions
DEFAULT_VERSION = 0
VERSIONS = [
    "D43J01",  # 0, OoT MQ-JP (Master Quest)
    # "D43E01",  # 1, OoT MQ-US (Master Quest)
    # "D43P01",  # 2, OoT MQ-EU (Master Quest)
    # "PZLJ01",  # 3, Zelda: CE-JP (Collector's Edition)
    # "PZLE01",  # 4, Zelda: CE-US (Collector's Edition)
    # "PZLP01",  # 5, Zelda: CE-EU (Collector's Edition)
]

parser = argparse.ArgumentParser()
parser.add_argument(
    "mode",
    choices=["configure", "progress"],
    default="configure",
    help="script mode (default: configure)",
    nargs="?",
)
parser.add_argument(
    "--version",
    choices=VERSIONS,
    type=str.upper,
    default=VERSIONS[DEFAULT_VERSION],
    help="version to build",
)
parser.add_argument(
    "--build-dir",
    metavar="DIR",
    type=Path,
    default=Path("build"),
    help="base build directory (default: build)",
)
parser.add_argument(
    "--binutils",
    metavar="BINARY",
    type=Path,
    help="path to binutils (optional)",
)
parser.add_argument(
    "--compilers",
    metavar="DIR",
    type=Path,
    help="path to compilers (optional)",
)
parser.add_argument(
    "--map",
    action="store_true",
    help="generate map file(s)",
    default=True,
)
parser.add_argument(
    "--no-asm",
    action="store_true",
    help="don't incorporate .s files from asm directory",
)
parser.add_argument(
    "--debug",
    action="store_true",
    help="build with debug info (non-matching)",
)
if not is_windows():
    parser.add_argument(
        "--wrapper",
        metavar="BINARY",
        type=Path,
        help="path to wibo or wine (optional)",
    )
parser.add_argument(
    "--dtk",
    metavar="BINARY | DIR",
    type=Path,
    help="path to decomp-toolkit binary or source (optional)",
)
parser.add_argument(
    "--sjiswrap",
    metavar="EXE",
    type=Path,
    help="path to sjiswrap.exe (optional)",
)
parser.add_argument(
    "--verbose",
    action="store_true",
    help="print verbose output",
)
args = parser.parse_args()

config = ProjectConfig()
config.version = args.version
version_num = VERSIONS.index(config.version)

# Apply arguments
config.build_dir = args.build_dir
config.dtk_path = args.dtk
config.binutils_path = args.binutils
config.compilers_path = args.compilers
config.debug = args.debug
config.generate_map = args.map
config.sjiswrap_path = args.sjiswrap
if not is_windows():
    config.wrapper = args.wrapper
if args.no_asm:
    config.asm_dir = None

# Tool versions
config.binutils_tag = "2.42-1"
config.compilers_tag = "20231018"
config.dtk_tag = "v0.7.5"
config.sjiswrap_tag = "v1.1.1"
config.wibo_tag = "0.6.11"

# Project
config.config_path = Path("config") / config.version / "config.yml"
config.check_sha_path = Path("config") / config.version / "build.sha1"
config.asflags = [
    "-mgekko",
    # "--strip-local-absolute",
    "-I include",
    f"-I build/{config.version}/include",
    f"--defsym version={version_num}",
]
config.ldflags = [
    "-fp hardware",
    "-nodefaults",
    "-warn off" # TODO: this is a temp solution until ``note.split`` is fixed
    # "-listclosure", # Uncomment for Wii linkers
]

# Base flags, common to most GC/Wii games.
# Generally leave untouched, with overrides added below.
cflags_base = [
    "-nodefaults",
    "-proc gekko",
    # "-align powerpc",
    "-enum int",
    "-fp hardware", # -fp hard
    "-Cpp_exceptions off",
    # # "-W all",
    "-O4,p",
    "-inline auto",
    # '-pragma "cats off"',
    # '-pragma "warn_notinlined off"',
    # "-maxerrors 1",
    # "-nosyspath",
    # "-RTTI off",
    "-fp_contract on",
    # "-str reuse",
    # "-multibyte",  # For Wii compilers, replace with `-enc SJIS`
    "-i include",
    f"-i build/{config.version}/include",
    f"-DVERSION={version_num}",
]

# Debug flags
if config.debug:
    cflags_base.extend(["-sym on", "-DDEBUG=1"])
else:
    cflags_base.append("-DNDEBUG=1")

cflags_dolphin = [
    *cflags_base,
    "-align powerpc",
    '-pragma "cats off"',
    '-pragma "warn_notinlined off"',
    "-maxerrors 1",
    "-nosyspath",
    "-RTTI off",
    "-str reuse",
    "-multibyte",  # For Wii compilers, replace with `-enc SJIS`
]

# Metrowerks library flags
cflags_runtime = [
    *cflags_base,
    "-msgstyle gcc",
    # "-use_lmw_stmw on",
    # "-str reuse,pool,readonly",
    # "-gccinc",
    # "-common off",
    "-inline auto,deferred",
]

# REL flags
cflags_rel = [
    *cflags_base,
    "-sdata 0",
    "-sdata2 0",
]

config.linker_version = "GC/1.1"


# Helper function for SIM objects
def SIM(lib_name: str, objects: List[Object]) -> Dict[str, Any]:
    return {
        "lib": lib_name,
        "mw_version": config.linker_version,
        "cflags": cflags_runtime,
        "host": False,
        "objects": objects,
    }


# Helper function for Dolphin libraries
def DolphinLib(lib_name: str, objects: List[Object]) -> Dict[str, Any]:
    return {
        "lib": lib_name,
        "mw_version": "GC/1.2.5n",
        "cflags": cflags_dolphin,
        "host": False,
        "objects": objects,
    }


# Helper function for REL script objects
def Rel(lib_name: str, objects: List[Object]) -> Dict[str, Any]:
    return {
        "lib": lib_name,
        "mw_version": "GC/1.3.2",
        "cflags": cflags_rel,
        "host": True,
        "objects": objects,
    }


Matching = True
NonMatching = False

config.warn_missing_config = True
config.warn_missing_source = False
config.libs = [
    SIM(
        "Core",
        [
            Object(Matching, "Core/xlCoreGCN.c"),
            Object(Matching, "Core/xlPostGCN.c"),
            Object(Matching, "Core/xlFileGCN.c"),
            Object(Matching, "Core/xlList.c"),
            Object(Matching, "Core/xlHeap.c"),
            Object(Matching, "Core/xlObject.c"),
        ]
    ),
    SIM(
        "Fire",
        [
            Object(NonMatching, "Fire/simGCN.c"),
            Object(Matching, "Fire/movie.c"),
            Object(NonMatching, "Fire/THPPlayer.c"),
            Object(NonMatching, "Fire/THPAudioDecode.c"),
            Object(NonMatching, "Fire/THPDraw.c"),
            Object(NonMatching, "Fire/THPRead.c"),
            Object(NonMatching, "Fire/THPVideoDecode.c"),
            Object(NonMatching, "Fire/mcardGCN.c"),
            Object(Matching, "Fire/codeGCN.c"),
            Object(NonMatching, "Fire/soundGCN.c"),
            Object(NonMatching, "Fire/frame.c"),
            Object(Matching, "Fire/system.c"),
            Object(NonMatching, "Fire/cpu.c"),
            Object(NonMatching, "Fire/pif.c"),
            Object(Matching, "Fire/ram.c"),
            Object(Matching, "Fire/rom.c"),
            Object(NonMatching, "Fire/rdp.c"),
            Object(Matching, "Fire/rdb.c"),
            Object(NonMatching, "Fire/rsp.c"),
            Object(Matching, "Fire/mips.c"),
            Object(Matching, "Fire/disk.c"),
            Object(Matching, "Fire/flash.c"),
            Object(Matching, "Fire/sram.c"),
            Object(Matching, "Fire/audio.c"),
            Object(Matching, "Fire/video.c"),
            Object(Matching, "Fire/serial.c"),
            Object(NonMatching, "Fire/library.c"),
            Object(Matching, "Fire/peripheral.c"),
            Object(NonMatching, "Fire/_frameGCNcc.c"),
            Object(NonMatching, "Fire/_buildtev.c"),
        ],
    ),
    DolphinLib(
        "base",
        [
            Object(NonMatching, "dolphin/base/PPCArch.c"),
        ],
    ),
    DolphinLib(
        "os",
        [
            Object(NonMatching, "dolphin/os/OS.c"),
            Object(NonMatching, "dolphin/os/OSAlarm.c"),
            Object(NonMatching, "dolphin/os/OSAlloc.c"),
            Object(NonMatching, "dolphin/os/OSArena.c"),
            Object(NonMatching, "dolphin/os/OSAudioSystem.c"),
            Object(NonMatching, "dolphin/os/OSCache.c"),
            Object(NonMatching, "dolphin/os/OSContext.c"),
            Object(NonMatching, "dolphin/os/OSError.c"),
            Object(NonMatching, "dolphin/os/OSFont.c"),
            Object(NonMatching, "dolphin/os/OSInterrupt.c"),
            Object(NonMatching, "dolphin/os/OSLink.c"),
            Object(NonMatching, "dolphin/os/OSMessage.c"),
            Object(NonMatching, "dolphin/os/OSMemory.c"),
            Object(NonMatching, "dolphin/os/OSMutex.c"),
            Object(NonMatching, "dolphin/os/OSReboot.c"),
            Object(NonMatching, "dolphin/os/OSReset.c"),
            Object(NonMatching, "dolphin/os/OSResetSW.c"),
            Object(NonMatching, "dolphin/os/OSRtc.c"),
            Object(NonMatching, "dolphin/os/OSSync.c"),
            Object(NonMatching, "dolphin/os/OSThread.c"),
            Object(NonMatching, "dolphin/os/OSTime.c"),
            Object(NonMatching, "dolphin/os/__start.c"),
            Object(NonMatching, "dolphin/os/__ppc_eabi_init.cpp"),
        ],
    ),
    DolphinLib(
        "exi",
        [
            Object(NonMatching, "dolphin/exi/EXIBios.c"),
            Object(NonMatching, "dolphin/exi/EXIUart.c"),
        ],
    ),
    DolphinLib(
        "si",
        [
            Object(NonMatching, "dolphin/si/SIBios.c"),
            Object(NonMatching, "dolphin/si/SISamplingRate.c"),
        ],
    ),
    DolphinLib(
        "vi",
        [
            Object(NonMatching, "dolphin/vi/vi.c"),
        ],
    ),
    DolphinLib(
        "db",
        [
            Object(NonMatching, "dolphin/db/db.c"),
        ],
    ),
    DolphinLib(
        "mtx",
        [
            Object(NonMatching, "dolphin/mtx/mtx.c", cflags=[*cflags_base, "-fp_contract off"]),
            Object(NonMatching, "dolphin/mtx/mtxvec.c"),
            Object(NonMatching, "dolphin/mtx/mtx44.c"),
        ],
    ),
    DolphinLib(
        "gx",
        [
            Object(NonMatching, "dolphin/gx/GXInit.c"),
            Object(NonMatching, "dolphin/gx/GXFifo.c"),
            Object(NonMatching, "dolphin/gx/GXAttr.c"),
            Object(NonMatching, "dolphin/gx/GXMisc.c"),
            Object(NonMatching, "dolphin/gx/GXGeometry.c"),
            Object(NonMatching, "dolphin/gx/GXFrameBuf.c"),
            Object(NonMatching, "dolphin/gx/GXLight.c"),
            Object(NonMatching, "dolphin/gx/GXTexture.c"),
            Object(NonMatching, "dolphin/gx/GXBump.c"),
            Object(NonMatching, "dolphin/gx/GXTev.c"),
            Object(NonMatching, "dolphin/gx/GXPixel.c"),
            Object(NonMatching, "dolphin/gx/GXTransform.c"),
            Object(NonMatching, "dolphin/gx/GXPerf.c"),
        ],
    ),
    DolphinLib(
        "pad",
        [
            Object(NonMatching, "dolphin/pad/Padclamp.c"),
            Object(NonMatching, "dolphin/pad/Pad.c"),
        ],
    ),
    DolphinLib(
        "dvd",
        [
            Object(NonMatching, "dolphin/dvd/dvdlow.c"),
            Object(NonMatching, "dolphin/dvd/dvdfs.c"),
            Object(NonMatching, "dolphin/dvd/dvd.c"),
            Object(NonMatching, "dolphin/dvd/dvdqueue.c"),
            Object(NonMatching, "dolphin/dvd/dvderror.c"),
            Object(NonMatching, "dolphin/dvd/dvdidutils.c"),
            Object(NonMatching, "dolphin/dvd/dvdFatal.c"),
            Object(NonMatching, "dolphin/dvd/fstload.c"),
        ],
    ),
    DolphinLib(
        "demo",
        [
            Object(NonMatching, "dolphin/demo/DEMOInit.c"),
            Object(NonMatching, "dolphin/demo/DEMOPuts.c"),
            Object(NonMatching, "dolphin/demo/DEMOFont.c"),
            Object(NonMatching, "dolphin/demo/DEMOPad.c"),
            Object(NonMatching, "dolphin/demo/DEMOStats.c"),
        ],
    ),
    # {
    #     "lib": "TRK_MINNOW_DOLPHIN",
    #     "mw_version": "GC/1.3.2",
    #     "cflags": cflags_runtime,
    #     "host": False,
    #     "objects": [
    #         Object(NonMatching, "TRK_MINNOW_DOLPHIN/Portable/mainloop.c"),
    #         Object(NonMatching, "TRK_MINNOW_DOLPHIN/Portable/nubevent.c"),
    #         Object(NonMatching, "TRK_MINNOW_DOLPHIN/Portable/nubinit.c"),
    #         Object(NonMatching, "TRK_MINNOW_DOLPHIN/Portable/msg.c"),
    #         Object(NonMatching, "TRK_MINNOW_DOLPHIN/Portable/msgbuf.c"),
    #         Object(NonMatching, "TRK_MINNOW_DOLPHIN/Portable/serpoll.c"),
    #         Object(NonMatching, "TRK_MINNOW_DOLPHIN/Portable/usr_put.c"),
    #         Object(NonMatching, "TRK_MINNOW_DOLPHIN/Portable/dispatch.c"),
    #         Object(NonMatching, "TRK_MINNOW_DOLPHIN/Portable/msghndlr.c"),
    #         Object(NonMatching, "TRK_MINNOW_DOLPHIN/Portable/support.c"),
    #         Object(NonMatching, "TRK_MINNOW_DOLPHIN/Portable/mutex_TRK.c"),
    #         Object(NonMatching, "TRK_MINNOW_DOLPHIN/Portable/notify.c"),
    #         Object(NonMatching, "TRK_MINNOW_DOLPHIN/ppc/Generic/flush_cache.c"),
    #         Object(NonMatching, "TRK_MINNOW_DOLPHIN/Portable/mem_TRK.c"),
    #         Object(NonMatching, "TRK_MINNOW_DOLPHIN/ppc/Generic/__exception.c"),
    #         Object(NonMatching, "TRK_MINNOW_DOLPHIN/ppc/Generic/targimpl.c"),
    #         Object(NonMatching, "TRK_MINNOW_DOLPHIN/Os/dolphin/dolphin_trk.c"),
    #         Object(NonMatching, "TRK_MINNOW_DOLPHIN/ppc/Generic/mpc_7xx_603e.c"),
    #         Object(NonMatching, "TRK_MINNOW_DOLPHIN/Portable/main_TRK.c"),
    #         Object(NonMatching, "TRK_MINNOW_DOLPHIN/Os/dolphin/dolphin_trk_glue.c"),
    #         Object(NonMatching, "TRK_MINNOW_DOLPHIN/Os/dolphin/targcont.c"),
    #     ],
    # },
    {
        "lib": "Runtime.PPCEABI.H",
        "mw_version": "GC/1.3.2",
        "cflags": cflags_runtime,
        "host": False,
        "objects": [
            Object(NonMatching, "PowerPC_EABI_Support/Runtime/Src/__mem.c"),
            Object(NonMatching, "PowerPC_EABI_Support/Runtime/Src/__va_arg.c"),
            Object(NonMatching, "PowerPC_EABI_Support/Runtime/Src/global_destructor_chain.c"),
            Object(NonMatching, "PowerPC_EABI_Support/Runtime/Src/runtime.c"),
        ],
    },
    # {
    #     "lib": "MSL_C",
    #     "mw_version": "GC/1.3.2",
    #     "cflags": cflags_runtime,
    #     "host": False,
    #     "objects": [
    #         Object(NonMatching, "PowerPC_EABI_Support/MSL/MSL_C/MSL_Common/Src/abort_exit.c"),
    #         Object(NonMatching, "PowerPC_EABI_Support/MSL/MSL_C/MSL_Common/Src/ansi_files.c"),
    #         Object(NonMatching, "PowerPC_EABI_Support/MSL/MSL_C/MSL_Common_Embedded/Src/ansi_fp.c", extra_cflags=["-inline noauto"]),
    #         Object(NonMatching, "PowerPC_EABI_Support/MSL/MSL_C/MSL_Common/Src/buffer_io.c"),
    #         Object(NonMatching, "PowerPC_EABI_Support/MSL/MSL_C/MSL_Common/Src/critical_regions.ppc_eabi.c"),
    #         Object(NonMatching, "PowerPC_EABI_Support/MSL/MSL_C/MSL_Common/Src/ctype.c"),
    #         Object(NonMatching, "PowerPC_EABI_Support/MSL/MSL_C/MSL_Common/Src/direct_io.c"),
    #         Object(NonMatching, "PowerPC_EABI_Support/MSL/MSL_C/MSL_Common/Src/errno.c"),
    #         Object(NonMatching, "PowerPC_EABI_Support/MSL/MSL_C/MSL_Common/Src/mbstring.c", extra_cflags=["-inline noauto"]),
    #         Object(NonMatching, "PowerPC_EABI_Support/MSL/MSL_C/MSL_Common/Src/mem.c"),
    #         Object(NonMatching, "PowerPC_EABI_Support/MSL/MSL_C/MSL_Common/Src/mem_funcs.c"),
    #         Object(NonMatching, "PowerPC_EABI_Support/MSL/MSL_C/MSL_Common/Src/misc_io.c"),
    #         Object(NonMatching, "PowerPC_EABI_Support/MSL/MSL_C/MSL_Common/Src/printf.c"),
    #         Object(NonMatching, "PowerPC_EABI_Support/MSL/MSL_C/MSL_Common/Src/scanf.c"),
    #         Object(NonMatching, "PowerPC_EABI_Support/MSL/MSL_C/MSL_Common/Src/string.c"),
    #         Object(NonMatching, "PowerPC_EABI_Support/MSL/MSL_C/MSL_Common/Src/strtoul.c"),
    #         Object(NonMatching, "PowerPC_EABI_Support/MSL/MSL_C/MSL_Common_Embedded/Src/uart_console_io.c"),
    #         Object(NonMatching, "PowerPC_EABI_Support/MSL/MSL_C/MSL_Common/Src/float.c"),
    #         Object(NonMatching, "PowerPC_EABI_Support/MSL/MSL_C/MSL_Common/Src/wchar_io.c"),
    #         Object(NonMatching, "PowerPC_EABI_Support/MSL/MSL_C/MSL_Common_Embedded/Math/Double_precision/e_asin.c"),
    #         Object(NonMatching, "PowerPC_EABI_Support/MSL/MSL_C/MSL_Common_Embedded/Math/Double_precision/e_pow.c"),
    #         Object(NonMatching, "PowerPC_EABI_Support/MSL/MSL_C/MSL_Common_Embedded/Math/Double_precision/fminmaxdim.c"),
    #         Object(NonMatching, "PowerPC_EABI_Support/MSL/MSL_C/MSL_Common_Embedded/Math/Double_precision/s_ceil.c"),
    #         Object(NonMatching, "PowerPC_EABI_Support/MSL/MSL_C/MSL_Common_Embedded/Math/Double_precision/s_copysign.c"),
    #         Object(NonMatching, "PowerPC_EABI_Support/MSL/MSL_C/MSL_Common_Embedded/Math/Double_precision/s_floor.c"),
    #         Object(NonMatching, "PowerPC_EABI_Support/MSL/MSL_C/MSL_Common_Embedded/Math/Double_precision/s_frexp.c"),
    #         Object(NonMatching, "PowerPC_EABI_Support/MSL/MSL_C/MSL_Common_Embedded/Math/Double_precision/s_ldexp.c"),
    #         Object(NonMatching, "PowerPC_EABI_Support/MSL/MSL_C/MSL_Common_Embedded/Math/Double_precision/w_pow.c"),
    #         Object(NonMatching, "PowerPC_EABI_Support/MSL/MSL_C/MSL_Common_Embedded/Math/Double_precision/hyperbolicsf.c"),
    #         Object(NonMatching, "PowerPC_EABI_Support/MSL/MSL_C/MSL_Common_Embedded/Math/Double_precision/log10f.c"),
    #         Object(NonMatching, "PowerPC_EABI_Support/MSL/MSL_C/MSL_Common_Embedded/Math/Double_precision/trigf.c"),
    #         Object(NonMatching, "PowerPC_EABI_Support/MSL/MSL_C/MSL_Common_Embedded/Math/Double_precision/math_inlines.c"),
    #         Object(NonMatching, "PowerPC_EABI_Support/MSL/MSL_C/MSL_Common_Embedded/Math/Double_precision/common_float_tables.c"),
    #     ],
    # },
    {
        "lib": "amcstubs",
        "mw_version": "GC/1.3.2",
        "cflags": cflags_runtime,
        "host": False,
        "objects": [
            Object(NonMatching, "amcstubs/AmcExi2Stubs.c"),
        ],
    },
    {
        "lib": "OdemuExi2",
        "mw_version": "GC/1.3.2",
        "cflags": cflags_runtime,
        "host": False,
        "objects": [
            Object(NonMatching, "OdemuExi2/DebuggerDriver.c"),
        ],
    },
    {
        "lib": "odenotstub",
        "mw_version": "GC/1.3.2",
        "cflags": cflags_runtime,
        "host": False,
        "objects": [
            Object(NonMatching, "odenotstub/odenotstub.c"),
        ],
    },
]

if args.mode == "configure":
    # Write build.ninja and objdiff.json
    generate_build(config)
elif args.mode == "progress":
    # Print progress and write progress.json
    config.progress_each_module = args.verbose
    calculate_progress(config)
else:
    sys.exit("Unknown mode: " + args.mode)
