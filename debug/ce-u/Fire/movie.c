/*
    Compile unit: C:\WINDOWS\Profiles\slee\Desktop\ENGLISH ZELDA\Fire\movie.c
    Producer: MW EABI PPC C-Compiler
    Language: C++
    Code range: 0x8000F7D8 -> 0x8000F89C
*/

#include "types.h"

// size = 0x4, address = 0x80137B10
u8* gBufferP;

// size = 0x4, address = 0x80137920
s32 __OSCurrHeap;

typedef enum __anon_0xEF59 {
    VI_TVMODE_NTSC_INT = 0,
    VI_TVMODE_NTSC_DS = 1,
    VI_TVMODE_NTSC_PROG = 2,
    VI_TVMODE_PAL_INT = 4,
    VI_TVMODE_PAL_DS = 5,
    VI_TVMODE_EURGB60_INT = 20,
    VI_TVMODE_EURGB60_DS = 21,
    VI_TVMODE_MPAL_INT = 8,
    VI_TVMODE_MPAL_DS = 9,
    VI_TVMODE_DEBUG_INT = 12,
    VI_TVMODE_DEBUG_PAL_INT = 16,
    VI_TVMODE_DEBUG_PAL_DS = 17,
} __anon_0xEF59;

typedef enum __anon_0xF0A1 {
    VI_XFBMODE_SF = 0,
    VI_XFBMODE_DF = 1,
} __anon_0xF0A1;

typedef struct _GXRenderModeObj {
    /* 0x00 */ enum __anon_0xEF59 viTVmode;
    /* 0x04 */ u16 fbWidth;
    /* 0x06 */ u16 efbHeight;
    /* 0x08 */ u16 xfbHeight;
    /* 0x0A */ u16 viXOrigin;
    /* 0x0C */ u16 viYOrigin;
    /* 0x0E */ u16 viWidth;
    /* 0x10 */ u16 viHeight;
    /* 0x14 */ enum __anon_0xF0A1 xFBmode;
    /* 0x18 */ u8 field_rendering;
    /* 0x19 */ u8 aa;
    /* 0x1A */ u8 sample_pattern[12][2];
    /* 0x32 */ u8 vfilter[7];
} __anon_0xF150; // size = 0x3C

// size = 0x4, address = 0x80137A9C
struct _GXRenderModeObj* rmode;

// Range: 0x8000F810 -> 0x8000F89C
void MovieInit() {
    // Local variables
    char* szText; // r1+0x8
    u32 size; // r4

    // References
    // -> u8* gBufferP;
    // -> s32 __OSCurrHeap;
}

// Erased
static void MovieUpdate() {}

// Range: 0x8000F7D8 -> 0x8000F810
void MovieDraw() {
    // References
    // -> struct _GXRenderModeObj* rmode;
}

// Erased
static void MovieDestroy() {
    // References
    // -> u8* gBufferP;
    // -> s32 __OSCurrHeap;
}
