#ifndef _SRAM_H
#define _SRAM_H

#include "dolphin.h"
#include "emulator/xlObject.h"

// __anon_0x74AB9
typedef struct Sram {
    void* pHost; // 0x0
} Sram;

s32 sramCopySRAM(Sram* pSRAM, s32 nOffsetRAM, s32 nOffsetSRAM, s32 nSize);
s32 sramTransferSRAM(Sram* pSRAM, s32 nOffsetRAM, s32 nOffsetSRAM, s32 nSize);
s32 sramEvent(Sram* pSram, s32 nEvent, void* pArgument);

extern _XL_OBJECTTYPE gClassSram;

#endif
