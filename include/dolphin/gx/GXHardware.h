#ifndef _DOLPHIN_GXHARDWARE_H
#define _DOLPHIN_GXHARDWARE_H

#include "dolphin/types.h"

#ifdef __cplusplus
extern "C" {
#endif // ifdef __cplusplus

#define GX_BITFIELD(field, pos, size, value) \
    (__rlwimi((field), (value), 31 - (pos) - (size) + 1, (pos), (pos) + (size) - 1))
#define GX_BITFIELD_SET(field, pos, size, value) ((field) = GX_BITFIELD(field, pos, size, value))
#define GX_BITFIELD_TRUNC(field, pos, size, value) (__rlwimi((field), (value), 0, (pos), (pos) + (size) - 1))
#define GX_BITGET(field, pos, size) ((field) >> (31 - (pos) - (size) + 1) & ((1 << (size)) - 1))

/**
 * Documentation from:
 * https://www.gc-forever.com/yagcd/chap8.html#sec8
 * https://www.gc-forever.com/yagcd/chap5.html#sec5
 * https://github.com/dolphin-emu/dolphin/blob/master/Source/Core/VideoCommon/BPMemory.h
 * https://github.com/dolphin-emu/dolphin/blob/master/Source/Core/VideoCommon/XFMemory.h
 * https://github.com/dolphin-emu/dolphin/blob/master/Source/Core/VideoCommon/OpcodeDecoding.h
 * https://patents.google.com/patent/US6700586B1/en
 * https://patents.google.com/patent/US6639595B1/en
 * https://patents.google.com/patent/US7002591
 * https://patents.google.com/patent/US6697074
 */

#define GX_REG_MASK(st, end) (((1 << ((end) - (st) + 1)) - 1) << 31 - (end))
#define GX_GET_REG(reg, st, end) GX_BITGET((reg), (st), ((end) - (st) + 1))
#define GX_SET_REG(reg, x, st, end) GX_BITFIELD_SET((reg), (st), ((end) - (st) + 1), (x))
#define GX_SET_TRUNC(reg, x, st, end) GX_BITFIELD_TRUNC((reg), (st), ((end) - (st) + 1), (x))

#define GET_REG_FIELD(reg, size, shift) ((int)((reg) >> (shift)) & ((1 << (size)) - 1))
#define SET_REG_FIELD(reg, size, shift, val)                                                \
    do {                                                                                    \
        (reg) = ((u32)(reg) & ~(((1 << (size)) - 1) << (shift))) | ((u32)(val) << (shift)); \
    } while (0)

#define GX_WRITE_RAS_REG(value) \
    do {                        \
        GX_WRITE_U8(0x61);      \
        GX_WRITE_U32(value);    \
        VERIF_RAS_REG(value);   \
    } while (0)

#define GX_WRITE_SOME_REG4(a, b, c, addr) \
    do {                                  \
        long regAddr;                     \
        GX_WRITE_U8(a);                   \
        GX_WRITE_U8(b);                   \
        GX_WRITE_U32(c);                  \
        regAddr = addr;                   \
    } while (0)

#define GX_WRITE_XF_REG_F(addr, value) \
    do {                               \
        GX_WRITE_F32(value);           \
    } while (0)

/************************************************************
 *
 *
 * GX FIFO
 *
 *
 ***********************************************************/

#define __GX_FIFO_SET_LOAD_INDX_DST(reg, x) ((reg) = GX_BITFIELD_SET(reg, 20, 12, x))
#define __GX_FIFO_SET_LOAD_INDX_NELEM(reg, x) ((reg) = GX_BITFIELD_SET(reg, 16, 4, x))
#define __GX_FIFO_SET_LOAD_INDX_INDEX(reg, x) ((reg) = GX_BITFIELD_SET(reg, 0, 16, x))

#define __GX_FIFO_LOAD_INDX(reg, dst, nelem, index) \
    {                                               \
        u32 cmd = 0;                                \
        __GX_FIFO_SET_LOAD_INDX_DST(cmd, dst);      \
        __GX_FIFO_SET_LOAD_INDX_NELEM(cmd, nelem);  \
        __GX_FIFO_SET_LOAD_INDX_INDEX(cmd, index);  \
        GXWGFifo.s8 = reg;                          \
        GXWGFifo.s32 = cmd;                         \
    }

#define GX_FIFO_LOAD_INDX_A(dst, nelem, index) __GX_FIFO_LOAD_INDX(GX_FIFO_CMD_LOAD_INDX_A, dst, nelem, index)

#define GX_FIFO_LOAD_INDX_B(dst, nelem, index) __GX_FIFO_LOAD_INDX(GX_FIFO_CMD_LOAD_INDX_B, dst, nelem, index)

#define GX_FIFO_LOAD_INDX_C(dst, nelem, index) __GX_FIFO_LOAD_INDX(GX_FIFO_CMD_LOAD_INDX_C, dst, nelem, index)

#define GX_FIFO_LOAD_INDX_D(dst, nelem, index) __GX_FIFO_LOAD_INDX(GX_FIFO_CMD_LOAD_INDX_D, dst, nelem, index)

/************************************************************
 *
 *
 * GX Blitting Processor (BP)
 *
 *
 ***********************************************************/

/**
 * Load immediate value into BP register
 */
#define GX_BP_LOAD_REG(data)               \
    GXWGFifo.s8 = GX_FIFO_CMD_LOAD_BP_REG; \
    GXWGFifo.s32 = (data);

/**
 * Set BP command opcode (first 8 bits)
 */
#define GX_BP_SET_OPCODE(cmd, opcode) (cmd) = GX_BITFIELD_SET(cmd, 0, 8, (opcode))

/************************************************************
 *
 *
 * GX Command Processor (CP)
 *
 *
 ***********************************************************/

/**
 * Load immediate value into CP register
 */
#define GX_CP_LOAD_REG(addr, data)         \
    GXWGFifo.s8 = GX_FIFO_CMD_LOAD_CP_REG; \
    GXWGFifo.s8 = (addr);                  \
    GXWGFifo.s32 = (data);

/************************************************************
 *
 *
 * GX Transform Unit (XF)
 *
 *
 ***********************************************************/

/**
 * Header for an XF register load
 */
#define GX_XF_LOAD_REG_HDR(addr)           \
    GXWGFifo.s8 = GX_FIFO_CMD_LOAD_XF_REG; \
    GXWGFifo.s32 = (addr);

/**
 * Load immediate value into XF register
 */
#define GX_XF_LOAD_REG(addr, data) \
    GX_XF_LOAD_REG_HDR(addr);      \
    GXWGFifo.s32 = (data);

/**
 * Load immediate values into multiple XF registers
 */
#define GX_XF_LOAD_REGS(size, addr)    \
    {                                  \
        u32 cmd = (size) << 16 | addr; \
        GX_XF_LOAD_REG_HDR(cmd);       \
    }

#ifdef __cplusplus
}
#endif
#endif
