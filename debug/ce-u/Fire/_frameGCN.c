/*
    Compile unit: C:\WINDOWS\Profiles\slee\Desktop\ENGLISH ZELDA\Fire\_frameGCN.c
    Producer: MW EABI PPC C-Compiler
    Language: C89
    Code range: 0x80021210 -> 0x8002CA20
*/

#include "types.h"

// Erased
static s32 frameSetProjection(struct __anon_0x24CE7* pFrame, s32 iHint) {
    // Parameters
    // struct __anon_0x24CE7* pFrame; // r30
    // s32 iHint; // r1+0xC

    // Local variables
    struct __anon_0x24B30* pHint; // r1+0x8
}

// Range: 0x8002C688 -> 0x8002CA20
static s32 frameDrawSetupFog_Zelda1(struct __anon_0x24CE7* pFrame) {
    // Parameters
    // struct __anon_0x24CE7* pFrame; // r1+0x8

    // Local variables
    enum _GXFogType nFogType; // r5
    f32 rNear; // r1+0x8
    f32 rFar; // f2
    u32 nMode; // r1+0x8
    u32 iHint; // r8
    f32 rFogNear; // f3
    f32 rFogFar; // f4
    f32 rFogMin; // f1
    f32 rFogMax; // f2
    f32 rMultiplier; // f6
    f32 rOffset; // f7
    f32 rMinimum; // f1
    f32 rMaximum; // f9
    f32 dplane; // f6
    f32 dplane; // f5
    f32 dplane; // f5
    f32 dplane; // f5
    f32 dplane; // f5
    f32 rFarScale; // f8
    f32 rNearScale; // f10

    // References
    // -> struct __anon_0x26AFD* gpSystem;
}

// Range: 0x8002C384 -> 0x8002C688
static s32 frameDrawSetupFog_Default(struct __anon_0x24CE7* pFrame) {
    // Parameters
    // struct __anon_0x24CE7* pFrame; // r31

    // Local variables
    s32 iHint; // r6
    f32 rNear; // f31
    f32 rFar; // f30
    f32 rFOVY; // f29
    f32 matrixProjection[4][4]; // r1+0x34
    struct _GXFogAdjTable fogTable; // r1+0x20
    f32 rMax; // f2
    f32 rMin; // r1+0x8
    f32 rIntpV; // f4
    f32 rMinimum; // r1+0x8
    f32 rMultiplier; // f3
    f32 rOffset; // r1+0x8
}

// Range: 0x8002C36C -> 0x8002C384
static void frameDrawSyncCallback(u16 nToken) {
    // Parameters
    // u16 nToken; // r1+0x0

    // References
    // -> static s32 sCopyFrameSyncReceived;
}

// Erased
static s32 frameSetVertexArray() {}

// Range: 0x8002C2F0 -> 0x8002C36C
static void frameDrawDone() {
    // References
    // -> s32 gNoSwapBuffer;
    // -> void* DemoCurrentBuffer;
    // -> void* DemoFrameBuffer2;
    // -> void* DemoFrameBuffer1;
    // -> static s32 gbFrameValid;
}

// Erased
static void* AllocateWrapper(u32 size) {
    // Parameters
    // u32 size; // r1+0x8

    // Local variables
    void* tempP; // r1+0xC
}

// Erased
static void* DeallocateWrapper(void* dataP) {
    // Parameters
    // void* dataP; // r1+0x8
}

// Erased
static void __DEMODoneRender() {
    // References
    // -> void* DemoCurrentBuffer;
}

// Range: 0x8002C184 -> 0x8002C2F0
static s32 frameMakeTLUT(struct __anon_0x24CE7* pFrame, struct _FRAME_TEXTURE* pTexture, s32 nCount, s32 nOffsetTMEM, s32 bReload) {
    // Parameters
    // struct __anon_0x24CE7* pFrame; // r29
    // struct _FRAME_TEXTURE* pTexture; // r28
    // s32 nCount; // r30
    // s32 nOffsetTMEM; // r31
    // s32 bReload; // r1+0x18

    // Local variables
    s32 iColor; // r5
    u16* anColor; // r3
    u16 nData16; // r1+0x8
}

// Erased
static s32 frameFreeTLUT(struct __anon_0x24CE7* pFrame, struct _FRAME_TEXTURE* pTexture) {
    // Parameters
    // struct __anon_0x24CE7* pFrame; // r1+0x0
    // struct _FRAME_TEXTURE* pTexture; // r1+0x4
}

// Range: 0x8002A790 -> 0x8002C184
static s32 frameMakePixels(struct __anon_0x24CE7* pFrame, struct _FRAME_TEXTURE* pTexture, struct __anon_0x2486E* pTile, s32 bReload) {
    // Parameters
    // struct __anon_0x24CE7* pFrame; // r19
    // struct _FRAME_TEXTURE* pTexture; // r16
    // struct __anon_0x2486E* pTile; // r26
    // s32 bReload; // r17

    // Local variables
    void* aPixel; // r24
    s32 nSizeLine; // r18
    s32 nFlip; // r9
    s32 nSize; // r1+0x40
    s32 nCount; // r1+0x8
    s32 nMode; // r1+0x8
    s32 nSizeX; // r30
    s32 nSizeY; // r15
    s32 nSource; // r10
    s32 nTarget; // r11
    s32 iPixelX; // r3
    s32 iPixelY; // r20
    s32 iTarget; // r1+0x8
    u8 nData8; // r31
    u16 nData16; // r31
    u32 nData32; // r31
    s32 nSizeTextureX; // r1+0x8
    s32 nSizeTextureY; // r26
    s32 lineX; // r1+0x8
    s32 lineY; // r1+0x8
    s32 linePixX; // r4
    s32 lineStep; // r5
    s32 tmemStart; // r21
    s32 tmemEnd; // r23
    s32 __nSizeX; // r5
    s32 __nSizeY; // r6
    u32 rgb[3]; // r1+0x24
    u32 yuv[3]; // r1+0x18

    // References
    // -> static u8 sRemapI$746[8];
}

// Erased
static s32 frameFreePixels(struct __anon_0x24CE7* pFrame, struct _FRAME_TEXTURE* pTexture) {
    // Parameters
    // struct __anon_0x24CE7* pFrame; // r30
    // struct _FRAME_TEXTURE* pTexture; // r31
}

// Range: 0x8002A4B4 -> 0x8002A790
static s32 frameLoadTexture(struct __anon_0x24CE7* pFrame, struct _FRAME_TEXTURE* pTexture, s32 iTextureCode, struct __anon_0x2486E* pTile) {
    // Parameters
    // struct __anon_0x24CE7* pFrame; // r26
    // struct _FRAME_TEXTURE* pTexture; // r27
    // s32 iTextureCode; // r1+0x18
    // struct __anon_0x2486E* pTile; // r1+0x1C

    // Local variables
    void* pData; // r4
    s32 iName; // r30
    s32 nFilter; // r4
    enum _GXTexWrapMode eWrapS; // r29
    enum _GXTexWrapMode eWrapT; // r28

    // References
    // -> enum _GXTexMapID ganNamePixel[8];
    // -> u32 ganNameColor[8];
}

// Range: 0x8002A308 -> 0x8002A4B4
s32 frameDrawSetup2D(struct __anon_0x24CE7* pFrame) {
    // Parameters
    // struct __anon_0x24CE7* pFrame; // r31

    // Local variables
    f32 matrix44[4][4]; // r1+0x10

    // References
    // -> static s32 snScissorChanged;
    // -> static u32 snScissorHeight;
    // -> static u32 snScissorWidth;
    // -> static u32 snScissorYOrig;
    // -> static u32 snScissorXOrig;
}

// Range: 0x80029954 -> 0x8002A308
static s32 frameDrawSetupSP(struct __anon_0x24CE7* pFrame, s32* pnColors, s32* pbFlag, s32 nVertexCount) {
    // Parameters
    // struct __anon_0x24CE7* pFrame; // r28
    // s32* pnColors; // r29
    // s32* pbFlag; // r30
    // s32 nVertexCount; // r31

    // Local variables
    f32 rValue23; // f1
    s32 bTextureGen; // r22
    f32 rNear; // f24
    f32 rFar; // f4
    f32 rScaleS; // f25
    f32 rScaleT; // f24
    f32 rSlideS; // f4
    f32 rSlideT; // f2
    struct _FRAME_TEXTURE* pTexture[8]; // r1+0x12C
    s32 nColors; // r21
    s32 bFlag; // r20
    s32 iTile; // r19
    s32 iHint; // r1+0x8
    f32 matrix[3][4]; // r1+0xFC
    f32 matrixA[3][4]; // r1+0xCC
    f32 matrixB[3][4]; // r1+0x9C
    f32 matrix44[4][4]; // r1+0x5C
    f32 matrixProjection[4][4]; // r1+0x1C
    enum _GXProjectionType eTypeProjection; // r4
    f32 scale; // r1+0x8
    s32 nCount; // r18
    s32 iIndex; // r6

    // References
    // -> u32 ganNameTexMtx[8];
    // -> static s32 snScissorChanged;
    // -> static u32 snScissorWidth;
    // -> static u32 snScissorHeight;
    // -> static u32 snScissorYOrig;
    // -> static u32 snScissorXOrig;
}

// Range: 0x80029858 -> 0x80029954
static s32 frameGetCombineColor(enum _GXTevColorArg* pnColorTEV, s32 nColorN64) {
    // Parameters
    // enum _GXTevColorArg* pnColorTEV; // r1+0x4
    // s32 nColorN64; // r1+0x8
}

// Range: 0x800297C8 -> 0x80029858
static s32 frameGetCombineAlpha(enum _GXTevAlphaArg* pnAlphaTEV, s32 nAlphaN64) {
    // Parameters
    // enum _GXTevAlphaArg* pnAlphaTEV; // r1+0x4
    // s32 nAlphaN64; // r1+0x8
}

// Range: 0x8002925C -> 0x800297C8
static s32 frameDrawSetupDP(struct __anon_0x24CE7* pFrame, s32* pnColors, s32* pbFlag) {
    // Parameters
    // struct __anon_0x24CE7* pFrame; // r31
    // s32* pnColors; // r1+0xC
    // s32* pbFlag; // r1+0x10

    // Local variables
    u32 nMode; // r1+0x8
    s32 numCycles; // r30
    u32 mode; // r1+0x8
    u32 cycle; // r4

    // References
    // -> struct __anon_0x26AFD* gpSystem;
}

// Range: 0x80029124 -> 0x8002925C
static s32 frameDrawTriangle_C0T0(struct __anon_0x24CE7* pFrame, struct __anon_0x2D50A* pPrimitive) {
    // Parameters
    // struct __anon_0x24CE7* pFrame; // r30
    // struct __anon_0x2D50A* pPrimitive; // r31

    // Local variables
    s32 iData; // r6
    u8* anData; // r7
    struct __anon_0x24073* pVertex; // r3
}

// Range: 0x80028F88 -> 0x80029124
static s32 frameDrawTriangle_C1T0(struct __anon_0x24CE7* pFrame, struct __anon_0x2D50A* pPrimitive) {
    // Parameters
    // struct __anon_0x24CE7* pFrame; // r30
    // struct __anon_0x2D50A* pPrimitive; // r31

    // Local variables
    s32 iData; // r10
    u8* anData; // r11
    struct __anon_0x24073* pVertex; // r1+0x8
    struct __anon_0x24073* pVertexColor; // r3
}

// Range: 0x80028DCC -> 0x80028F88
static s32 frameDrawTriangle_C3T0(struct __anon_0x24CE7* pFrame, struct __anon_0x2D50A* pPrimitive) {
    // Parameters
    // struct __anon_0x24CE7* pFrame; // r30
    // struct __anon_0x2D50A* pPrimitive; // r31

    // Local variables
    s32 iData; // r9
    u8* anData; // r10
    struct __anon_0x24073* pVertex; // r8
}

// Range: 0x80028C40 -> 0x80028DCC
static s32 frameDrawTriangle_C0T3(struct __anon_0x24CE7* pFrame, struct __anon_0x2D50A* pPrimitive) {
    // Parameters
    // struct __anon_0x24CE7* pFrame; // r30
    // struct __anon_0x2D50A* pPrimitive; // r31

    // Local variables
    s32 iData; // r6
    u8* anData; // r7
    struct __anon_0x24073* pVertex; // r3
}

// Range: 0x80028A50 -> 0x80028C40
static s32 frameDrawTriangle_C1T3(struct __anon_0x24CE7* pFrame, struct __anon_0x2D50A* pPrimitive) {
    // Parameters
    // struct __anon_0x24CE7* pFrame; // r30
    // struct __anon_0x2D50A* pPrimitive; // r31

    // Local variables
    s32 iData; // r10
    u8* anData; // r11
    struct __anon_0x24073* pVertex; // r1+0x8
    struct __anon_0x24073* pVertexColor; // r3
}

// Range: 0x80027B8C -> 0x80028A50
static s32 frameCheckTriangleDivide(struct __anon_0x24CE7* pFrame, struct __anon_0x2D50A* pPrimitive) {
    // Parameters
    // struct __anon_0x24CE7* pFrame; // r22
    // struct __anon_0x2D50A* pPrimitive; // r23

    // Local variables
    s32 iData; // r25
    u8* anData; // r24
    struct __anon_0x24073 aNewVertArray[8]; // r1+0x184
    f32 fInterp; // r1+0x8
    f32 fTempColor1; // f2
    f32 fTempColor2; // f3
    u32 nNewVertCount; // r5
    u32 bInFront; // r7
    u32 bBehind; // r8
}

// Range: 0x800279E8 -> 0x80027B8C
static s32 frameDrawTriangle_C3T3(struct __anon_0x24CE7* pFrame, struct __anon_0x2D50A* pPrimitive) {
    // Parameters
    // struct __anon_0x24CE7* pFrame; // r29
    // struct __anon_0x2D50A* pPrimitive; // r30

    // Local variables
    f32 (* pMatrix)[4]; // r3

    // References
    // -> static u32 gHackCreditsColor;
    // -> struct __anon_0x26AFD* gpSystem;
}

// Range: 0x8002790C -> 0x800279E8
static s32 frameDrawTriangle_Setup(struct __anon_0x24CE7* pFrame, struct __anon_0x2D50A* pPrimitive) {
    // Parameters
    // struct __anon_0x24CE7* pFrame; // r30
    // struct __anon_0x2D50A* pPrimitive; // r31

    // Local variables
    s32 bFlag; // r1+0x14
    s32 nColors; // r1+0x10

    // References
    // -> static s32 (* gapfDrawTriangle[8])(void*, void*);
}

// Range: 0x80027798 -> 0x8002790C
static s32 frameDrawLine_C0T0(struct __anon_0x24CE7* pFrame, struct __anon_0x2D50A* pPrimitive) {
    // Parameters
    // struct __anon_0x24CE7* pFrame; // r29
    // struct __anon_0x2D50A* pPrimitive; // r30

    // Local variables
    s32 iData; // r6
    u8* anData; // r31
    struct __anon_0x24073* pVertex; // r3
}

// Range: 0x800275D0 -> 0x80027798
static s32 frameDrawLine_C1T0(struct __anon_0x24CE7* pFrame, struct __anon_0x2D50A* pPrimitive) {
    // Parameters
    // struct __anon_0x24CE7* pFrame; // r29
    // struct __anon_0x2D50A* pPrimitive; // r30

    // Local variables
    s32 iData; // r10
    u8* anData; // r31
    struct __anon_0x24073* pVertex; // r1+0x8
    struct __anon_0x24073* pVertexColor; // r3
}

// Range: 0x800273F8 -> 0x800275D0
static s32 frameDrawLine_C2T0(struct __anon_0x24CE7* pFrame, struct __anon_0x2D50A* pPrimitive) {
    // Parameters
    // struct __anon_0x24CE7* pFrame; // r29
    // struct __anon_0x2D50A* pPrimitive; // r30

    // Local variables
    s32 iData; // r8
    u8* anData; // r31
    struct __anon_0x24073* pVertex; // r9
}

// Range: 0x80027240 -> 0x800273F8
static s32 frameDrawLine_C0T2(struct __anon_0x24CE7* pFrame, struct __anon_0x2D50A* pPrimitive) {
    // Parameters
    // struct __anon_0x24CE7* pFrame; // r29
    // struct __anon_0x2D50A* pPrimitive; // r30

    // Local variables
    s32 iData; // r6
    u8* anData; // r31
    struct __anon_0x24073* pVertex; // r3
}

// Range: 0x80027034 -> 0x80027240
static s32 frameDrawLine_C1T2(struct __anon_0x24CE7* pFrame, struct __anon_0x2D50A* pPrimitive) {
    // Parameters
    // struct __anon_0x24CE7* pFrame; // r29
    // struct __anon_0x2D50A* pPrimitive; // r30

    // Local variables
    s32 iData; // r10
    u8* anData; // r31
    struct __anon_0x24073* pVertex; // r1+0x8
    struct __anon_0x24073* pVertexColor; // r3
}

// Range: 0x80026E18 -> 0x80027034
static s32 frameDrawLine_C2T2(struct __anon_0x24CE7* pFrame, struct __anon_0x2D50A* pPrimitive) {
    // Parameters
    // struct __anon_0x24CE7* pFrame; // r29
    // struct __anon_0x2D50A* pPrimitive; // r30

    // Local variables
    s32 iData; // r8
    u8* anData; // r31
    struct __anon_0x24073* pVertex; // r9
}

// Range: 0x80026D3C -> 0x80026E18
static s32 frameDrawLine_Setup(struct __anon_0x24CE7* pFrame, struct __anon_0x2D50A* pPrimitive) {
    // Parameters
    // struct __anon_0x24CE7* pFrame; // r30
    // struct __anon_0x2D50A* pPrimitive; // r31

    // Local variables
    s32 bFlag; // r1+0x14
    s32 nColors; // r1+0x10

    // References
    // -> static s32 (* gapfDrawLine[6])(void*, void*);
}

// Range: 0x80026AA8 -> 0x80026D3C
static s32 frameDrawRectFill(struct __anon_0x24CE7* pFrame, struct __anon_0x2D365* pRectangle) {
    // Parameters
    // struct __anon_0x24CE7* pFrame; // r1+0x8
    // struct __anon_0x2D365* pRectangle; // r1+0xC

    // Local variables
    s32 bFlag; // r8
    f32 rDepth; // f31
    f32 rX0; // f30
    f32 rY0; // f29
    f32 rX1; // f28
    f32 rY1; // f27
}

// Range: 0x800269F8 -> 0x80026AA8
static s32 frameDrawRectFill_Setup(struct __anon_0x24CE7* pFrame, struct __anon_0x2D365* pRectangle) {
    // Parameters
    // struct __anon_0x24CE7* pFrame; // r30
    // struct __anon_0x2D365* pRectangle; // r31

    // Local variables
    s32 bFlag; // r1+0x14
    s32 nColors; // r1+0x10
}

// Range: 0x80026520 -> 0x800269F8
static s32 frameDrawRectTexture(struct __anon_0x24CE7* pFrame, struct __anon_0x2D365* pRectangle) {
    // Parameters
    // struct __anon_0x24CE7* pFrame; // r30
    // struct __anon_0x2D365* pRectangle; // r31

    // Local variables
    s32 bCopy; // r11
    f32 rDepth; // f31
    f32 rDeltaT; // f5
    f32 rX0; // f30
    f32 rY0; // f29
    f32 rX1; // f28
    f32 rY1; // f27
    f32 rS0; // f26
    f32 rT0; // f25
    f32 rS1; // f24
    f32 rT1; // f23

    // References
    // -> static s32 gnCountMapHack;
    // -> struct __anon_0x26AFD* gpSystem;
    // -> static u8 sSpecialZeldaHackON;
    // -> static s32 nCounter$1367;
}

// Range: 0x80026130 -> 0x80026520
static s32 frameDrawRectTexture_Setup(struct __anon_0x24CE7* pFrame, struct __anon_0x2D365* pRectangle) {
    // Parameters
    // struct __anon_0x24CE7* pFrame; // r22
    // struct __anon_0x2D365* pRectangle; // r23

    // Local variables
    f32 matrix[3][4]; // r1+0x98
    f32 matrixA[3][4]; // r1+0x68
    f32 matrixB[3][4]; // r1+0x38
    struct _FRAME_TEXTURE* pTexture[8]; // r1+0x18
    f32 rScaleS; // f29
    f32 rScaleT; // f28
    f32 rSlideS; // f2
    f32 rSlideT; // r1+0x8
    u32 bFlag; // r1+0x14
    u32 nColors; // r1+0x10
    s32 iTile; // r25
    s32 firstTile; // r3
    s32 nCount; // r24
    s32 iIndex; // r6
    char cTempAlpha; // r20

    // References
    // -> static s32 bSkip$1410;
    // -> struct __anon_0x26AFD* gpSystem;
    // -> u32 ganNameTexMtx[8];
    // -> static u8 sSpecialZeldaHackON;
}

// Erased
static s32 frameTick() {}

// Erased
static s32 frameDraw() {}

// Erased
static void CopyZBuffer() {}

// Range: 0x80026128 -> 0x80026130
s32 frameShow() {}

// Erased
static s32 frameHide() {}

// Range: 0x80026000 -> 0x80026128
s32 frameSetScissor(struct __anon_0x24CE7* pFrame, struct __anon_0x2D365* pScissor) {
    // Parameters
    // struct __anon_0x24CE7* pFrame; // r1+0x8
    // struct __anon_0x2D365* pScissor; // r1+0xC

    // Local variables
    s32 nTemp; // r1+0x8
    s32 nX0; // r3
    s32 nY0; // r4
    s32 nX1; // r5
    s32 nY1; // r6
}

// Erased
static s32 frameGetScissor() {}

// Range: 0x80025FF0 -> 0x80026000
s32 frameSetDepth(struct __anon_0x24CE7* pFrame, f32 rDepth, f32 rDelta) {
    // Parameters
    // struct __anon_0x24CE7* pFrame; // r1+0x0
    // f32 rDepth; // r1+0x4
    // f32 rDelta; // r1+0x8
}

// Range: 0x80025EF4 -> 0x80025FF0
s32 frameSetColor(struct __anon_0x24CE7* pFrame, enum __anon_0x2D2D2 eType, u32 nRGBA) {
    // Parameters
    // struct __anon_0x24CE7* pFrame; // r31
    // enum __anon_0x2D2D2 eType; // r30
    // u32 nRGBA; // r1+0x10
}

// Range: 0x80025ED8 -> 0x80025EF4
s32 frameBeginOK() {
    // References
    // -> static s32 gbFrameValid;
}

// Range: 0x80025C4C -> 0x80025ED8
s32 frameBegin(struct __anon_0x24CE7* pFrame, s32 nCountVertex) {
    // Parameters
    // struct __anon_0x24CE7* pFrame; // r31
    // s32 nCountVertex; // r28

    // Local variables
    s32 i; // r28
    f32 matrix[3][4]; // r1+0x14

    // References
    // -> enum _GXTexCoordID ganNameTexCoord[8];
    // -> u32 ganNameTexMtx[8];
    // -> static s32 gbFrameValid;
    // -> static s32 gbFrameBegin;
}

// Range: 0x800259C4 -> 0x80025C4C
s32 frameEnd(struct __anon_0x24CE7* pFrame) {
    // Parameters
    // struct __anon_0x24CE7* pFrame; // r30

    // Local variables
    struct _CPU* pCPU; // r31
    s32 iHint; // r7
    void* pData; // r29

    // References
    // -> struct __anon_0x26AFD* gpSystem;
    // -> void* DemoCurrentBuffer;
    // -> static s32 sCopyFrameSyncReceived;
    // -> static u16 sTempZBuf[4800][4][4];
    // -> static s32 gbFrameValid;
    // -> static s32 gbFrameBegin;
}

// Range: 0x8002589C -> 0x800259C4
s32 _frameDrawRectangle(struct __anon_0x24CE7* pFrame, u32 nColor, s32 nX, s32 nY, s32 nSizeX, s32 nSizeY) {
    // Parameters
    // struct __anon_0x24CE7* pFrame; // r1+0x0
    // u32 nColor; // r1+0x4
    // s32 nX; // r11
    // s32 nY; // r1+0xC
    // s32 nSizeX; // r7
    // s32 nSizeY; // r1+0x14

    // Local variables
    s32 iY; // r10
    s32 iX; // r11
    u32* pnPixel; // r3
    s32 nSizeTargetX; // r9

    // References
    // -> void* DemoFrameBuffer2;
    // -> void* DemoFrameBuffer1;
    // -> void* DemoCurrentBuffer;
}

// Erased
static s32 _frameDrawImage(struct __anon_0x24CE7* pFrame, u16* pnImage, s32 nSizeX, s32 nSizeY, s32 nX0, s32 nY0, s32 bAlpha) {
    // Parameters
    // struct __anon_0x24CE7* pFrame; // r1+0x8
    // u16* pnImage; // r1+0xC
    // s32 nSizeX; // r1+0x10
    // s32 nSizeY; // r1+0x14
    // s32 nX0; // r1+0x18
    // s32 nY0; // r1+0x1C
    // s32 bAlpha; // r1+0x20

    // Local variables
    s32 iY; // r30
    s32 iX; // r1+0x8
    s32 nSizeTargetX; // r30
    u32* pnPixel; // r3
    u32* aPixel; // r29
    u32 nPixelSource; // r7
    u32 nPixelTarget; // r29

    // References
    // -> void* DemoFrameBuffer2;
    // -> void* DemoFrameBuffer1;
    // -> void* DemoCurrentBuffer;
}

// Erased
static void ZeldaDrawFrameZTexture(struct __anon_0x24CE7* pFrame, u32* pData) {
    // Parameters
    // struct __anon_0x24CE7* pFrame; // r3
    // u32* pData; // r30

    // Local variables
    f32 matrix[3][4]; // r1+0x30

    // References
    // -> static struct _GXTexObj sFrameObj1$1562;
}

// Range: 0x800256A8 -> 0x8002589C
void ZeldaDrawFrameNoBlend(struct __anon_0x24CE7* pFrame, u16* pData) {
    // Parameters
    // struct __anon_0x24CE7* pFrame; // r3
    // u16* pData; // r30

    // Local variables
    f32 matrix[3][4]; // r1+0x30

    // References
    // -> static struct _GXTexObj sFrameObj$1564;
}

// Range: 0x800253C4 -> 0x800256A8
void ZeldaDrawFrameBlur(struct __anon_0x24CE7* pFrame, u16* pData) {
    // Parameters
    // struct __anon_0x24CE7* pFrame; // r31
    // u16* pData; // r29

    // Local variables
    f32 matrix[3][4]; // r1+0x38
    struct _GXColor color; // r1+0x14

    // References
    // -> static struct _GXTexObj sFrameObj$1565;
}

// Range: 0x800250E4 -> 0x800253C4
void ZeldaDrawFrame(struct __anon_0x24CE7* pFrame, u16* pData) {
    // Parameters
    // struct __anon_0x24CE7* pFrame; // r31
    // u16* pData; // r29

    // Local variables
    f32 matrix[3][4]; // r1+0x38
    struct _GXColor color; // r1+0x14

    // References
    // -> static struct _GXTexObj sFrameObj$1568;
}

// Erased
static void CopyCFBAlpha(u8* srcP) {
    // Parameters
    // u8* srcP; // r31

    // References
    // -> static s32 sCopyFrameSyncReceived;
}

// Erased
static void CopyCFBZTexture(u32* srcP) {
    // Parameters
    // u32* srcP; // r31

    // References
    // -> static s32 sCopyFrameSyncReceived;
}

// Erased
static void ConvertZ(u16* srcP) {
    // Parameters
    // u16* srcP; // r29

    // Local variables
    u16* dataEndP; // r30
    s32 tile; // r7
    s32 y; // r8
    s32 x; // r1+0x8
    u16 val; // r9

    // References
    // -> static u32 line$1582[80][4][4];
}

// Erased
static void CopyCFB(u16* srcP) {
    // Parameters
    // u16* srcP; // r31

    // References
    // -> static s32 sCopyFrameSyncReceived;
}

// Erased
static void ConvertCFB(u16* srcP) {
    // Parameters
    // u16* srcP; // r29

    // Local variables
    u16* dataEndP; // r30
    s32 tile; // r6
    s32 y; // r7
    s32 x; // r1+0x8
    u16 val; // r1+0x8

    // References
    // -> static u16 line$1606[80][4][4];
}

// Range: 0x80024DA0 -> 0x800250E4
void CopyAndConvertCFB(u16* srcP) {
    // Parameters
    // u16* srcP; // r29

    // Local variables
    u16* dataEndP; // r30
    s32 tile; // r6
    s32 y; // r7
    s32 x; // r1+0x8
    u16 val; // r1+0x8

    // References
    // -> static u16 line$1630[80][4][4];
    // -> static s32 sCopyFrameSyncReceived;
}

// Range: 0x80024A10 -> 0x80024DA0
static void ZeldaGreyScaleConvert(struct __anon_0x24CE7* pFrame) {
    // Parameters
    // struct __anon_0x24CE7* pFrame; // r31

    // Local variables
    f32 matrix[3][4]; // r1+0x38
    void* dataP; // r29
    struct _GXColor color; // r1+0x10

    // References
    // -> static struct _GXTexObj sFrameObj$1647;
    // -> static u8 cAlpha$1648;
    // -> static u32 gHackCreditsColor;
    // -> void* DemoCurrentBuffer;
}

// Erased
static void ZeldaCopyFrameHiRes(void* pSrc) {
    // Parameters
    // void* pSrc; // r31

    // References
    // -> static s32 sCopyFrameSyncReceived;
}

// Erased
static void ZeldaDrawFrameHiRes(struct __anon_0x24CE7* pFrame, void* pSrc) {
    // Parameters
    // struct __anon_0x24CE7* pFrame; // r31
    // void* pSrc; // r29

    // Local variables
    f32 matrix[3][4]; // r1+0x38
    struct _GXColor color; // r1+0x14

    // References
    // -> static struct _GXTexObj sFrameObj$1660;
}

// Range: 0x80024504 -> 0x80024A10
void ZeldaDrawFrameShrink(struct __anon_0x24CE7* pFrame, s32 posX, s32 posY, s32 size) {
    // Parameters
    // struct __anon_0x24CE7* pFrame; // r30
    // s32 posX; // r1+0xC
    // s32 posY; // r1+0x10
    // s32 size; // r1+0x14

    // Local variables
    f32 matrix[3][4]; // r1+0x28
    f32 nX0; // f31
    f32 nX1; // f30
    f32 nY0; // f29
    f32 nY1; // f28
    f32 scale; // f4
    void* frameBuffer; // r26
    struct _GXColor color; // r1+0x20

    // References
    // -> static struct _GXTexObj frameObj$1663;
    // -> void* DemoCurrentBuffer;
}

// Erased
static void ZeldaCopyCamera(u16* buffer) {
    // Parameters
    // u16* buffer; // r31
}

// Range: 0x80024210 -> 0x80024504
void ZeldaDrawFrameCamera(struct __anon_0x24CE7* pFrame, void* buffer) {
    // Parameters
    // struct __anon_0x24CE7* pFrame; // r31
    // void* buffer; // r29

    // Local variables
    f32 matrix[3][4]; // r1+0x30
    struct _GXColor color; // r1+0x2C

    // References
    // -> static struct _GXTexObj frameObj$1673;
}

// Range: 0x80024048 -> 0x80024210
s32 frameHackTIMG_Zelda(struct __anon_0x24CE7* pFrame, u64** pnGBI, u32* pnCommandLo, u32* pnCommandHi) {
    // Parameters
    // struct __anon_0x24CE7* pFrame; // r3
    // u64** pnGBI; // r30
    // u32* pnCommandLo; // r31
    // u32* pnCommandHi; // r1+0x14

    // Local variables
    u32 i; // r7

    // References
    // -> static u32 sDestinationBuffer;
    // -> struct __anon_0x26AFD* gpSystem;
    // -> static u32 sSrcBuffer;
    // -> static u8 sSpecialZeldaHackON;
    // -> static u32 sCommandCodes$1679[8];
}

// Range: 0x800239F0 -> 0x80024048
s32 frameHackCIMG_Zelda2(struct __anon_0x24CE7* pFrame, struct __anon_0x23C4D* pBuffer, u64* pnGBI) {
    // Parameters
    // struct __anon_0x24CE7* pFrame; // r30
    // struct __anon_0x23C4D* pBuffer; // r31
    // u64* pnGBI; // r1+0x10

    // Local variables
    u32 i; // r7
    u32* pGBI; // r8

    // References
    // -> static s32 sCopyFrameSyncReceived;
    // -> s32 gNoSwapBuffer;
    // -> static s32 nLastFrame$1695;
    // -> static s32 nCopyFrame$1697;
    // -> static u32 sCommandCodes2$1722[10];
    // -> static u32 sCommandCodes$1702[10];
}

// Range: 0x800235B0 -> 0x800239F0
s32 frameHackCIMG_Zelda(struct __anon_0x24CE7* pFrame, struct __anon_0x23C4D* pBuffer, u64* pnGBI, u32 nCommandLo) {
    // Parameters
    // struct __anon_0x24CE7* pFrame; // r1+0x8
    // struct __anon_0x23C4D* pBuffer; // r28
    // u64* pnGBI; // r1+0x10
    // u32 nCommandLo; // r29

    // Local variables
    u32 i; // r30
    u32 low2; // r1+0x8
    u32 high2; // r1+0x8
    u16* srcP; // r1+0x20
    u16* val; // r27
    u16* valEnd; // r29
    s32 tile; // r6
    s32 y; // r7
    s32 x; // r1+0x8
    u8* val; // r3
    u8* valEnd; // r4

    // References
    // -> static u16 tempLine$1785[16][4][4];
    // -> static s32 sCopyFrameSyncReceived;
    // -> s32 gNoSwapBuffer;
    // -> static u32 sNumAddr;
    // -> static u32 sConstantBufAddr[6];
    // -> static s32 gnCountMapHack;
    // -> static u32 sSrcBuffer;
    // -> static u32 sDestinationBuffer;
    // -> struct __anon_0x26AFD* gpSystem;
}

// Range: 0x8002343C -> 0x800235B0
s32 frameHackCIMG_Zelda2_Shrink(struct __anon_0x2870E* pRDP, struct __anon_0x24CE7* pFrame, u64** ppnGBI) {
    // Parameters
    // struct __anon_0x2870E* pRDP; // r1+0x8
    // struct __anon_0x24CE7* pFrame; // r27
    // u64** ppnGBI; // r28

    // Local variables
    u64* pnGBI; // r30
    s32 count; // r8
    s32 nAddress; // r4
    u32 nCommandLo; // r6
    u32 nCommandHi; // r1+0x8
    struct __anon_0x2988F* pRSP; // r29
    s32 done; // r3
    union __anon_0x2AD52 bg; // r1+0x18

    // References
    // -> static u32 GBIcode$1816[3];
}

// Range: 0x80023308 -> 0x8002343C
s32 frameHackCIMG_Zelda2_Camera(struct __anon_0x24CE7* pFrame, struct __anon_0x23C4D* pBuffer, u32 nCommandHi, u32 nCommandLo) {
    // Parameters
    // struct __anon_0x24CE7* pFrame; // r31
    // struct __anon_0x23C4D* pBuffer; // r1+0xC
    // u32 nCommandHi; // r1+0x10
    // u32 nCommandLo; // r1+0x14
}

// Range: 0x8002325C -> 0x80023308
void PanelDrawBG8(u16* BG, u16* LUT, u8* bitmap, s32 sizeX, s32 sizeY, s32 posX, s32 posY, s32 flip) {
    // Parameters
    // u16* BG; // r1+0x8
    // u16* LUT; // r1+0xC
    // u8* bitmap; // r1+0x10
    // s32 sizeX; // r1+0x14
    // s32 sizeY; // r1+0x18
    // s32 posX; // r1+0x1C
    // s32 posY; // r1+0x20
    // s32 flip; // r1+0x24

    // Local variables
    s32 i; // r28
    s32 j; // r27
    u16 color; // r1+0x8
}

// Range: 0x800231A0 -> 0x8002325C
void PanelDrawBG16(u16* BG, u16* bitmap, s32 sizeX, s32 sizeY, s32 posX, s32 posY, s32 flip) {
    // Parameters
    // u16* BG; // r1+0x8
    // u16* bitmap; // r1+0xC
    // s32 sizeX; // r1+0x10
    // s32 sizeY; // r1+0x14
    // s32 posX; // r1+0x18
    // s32 posY; // r1+0x1C
    // s32 flip; // r1+0x20

    // Local variables
    s32 i; // r29
    s32 j; // r28
    u16 color; // r1+0x8
}

// Range: 0x800230EC -> 0x800231A0
void PanelDrawFR3D(u16* FR, u16* LUT, u8* bitmap, s32 sizeX, s32 sizeY, s32 posX, s32 posY, s32 first) {
    // Parameters
    // u16* FR; // r1+0x8
    // u16* LUT; // r1+0xC
    // u8* bitmap; // r1+0x10
    // s32 sizeX; // r1+0x14
    // s32 sizeY; // r1+0x18
    // s32 posX; // r1+0x1C
    // s32 posY; // r1+0x20
    // s32 first; // r1+0x24

    // Local variables
    s32 i; // r30
    s32 j; // r1+0x8
    u16 color; // r29
}

// Range: 0x80023048 -> 0x800230EC
s32 frameHackTIMG_Panel(struct __anon_0x24CE7* pFrame, struct __anon_0x23C4D* pBuffer) {
    // Parameters
    // struct __anon_0x24CE7* pFrame; // r1+0x0
    // struct __anon_0x23C4D* pBuffer; // r1+0x4
}

// Range: 0x80021804 -> 0x80023048
s32 frameHackCIMG_Panel(struct __anon_0x2870E* pRDP, struct __anon_0x24CE7* pFrame, struct __anon_0x23C4D* pBuffer, u64** ppnGBI) {
    // Parameters
    // struct __anon_0x2870E* pRDP; // r29
    // struct __anon_0x24CE7* pFrame; // r30
    // struct __anon_0x23C4D* pBuffer; // r17
    // u64** ppnGBI; // r14

    // Local variables
    struct __anon_0x2988F* pRSP; // r17
    u64* pnGBI; // r20
    s32 count; // r8
    s32 nAddress; // r5
    s32 sizeX; // r6
    u32 nCommandLo; // r7
    u32 nCommandHi; // r3
    u16* BG; // r18
    u16* FR; // r28
    u16* pLUT; // r16
    u16* pBitmap16; // r4
    u8* pBitmap8; // r5
    s32 iTile; // r5
    s32 nCount; // r4
    struct __anon_0x2486E* pTile; // r5
    s32 iTile; // r1+0x8
    s32 nCount; // r4
    s32 iTile; // r5
    s32 nCount; // r4
    union __anon_0x2AD52 bg; // r1+0x50
    union __anon_0x2B140 objTxtr; // r1+0x38
    u32 nLoadType; // r1+0x34
    struct __anon_0x23C4D* pBG; // r18

    // References
    // -> static u32 GBIcode2D2$1906[7];
    // -> static u32 GBIcode3D2$1908[6];
    // -> static u32 GBIcode3D1$1907[5];
}

// Range: 0x80021594 -> 0x80021804
s32 frameGetDepth(struct __anon_0x24CE7* pFrame, u16* pnData, s32 nAddress) {
    // Parameters
    // struct __anon_0x24CE7* pFrame; // r1+0x8
    // u16* pnData; // r1+0xC
    // s32 nAddress; // r1+0x10

    // Local variables
    u32 nX; // r7
    u32 nY; // r8
    u32 nOffset; // r1+0x8
    s32 n64CalcValue; // r6
    s32 exp; // r7
    s32 mantissa; // r1+0x8
    s32 compare; // r3
    s32 val; // r7
    struct __anon_0x28694 z_format[8]; // r1+0x14

    // References
    // -> static u16 sTempZBuf[4800][4][4];
}

// Range: 0x80021210 -> 0x80021594
static s32 frameEvent(struct __anon_0x24CE7* pFrame, s32 nEvent) {
    // Parameters
    // struct __anon_0x24CE7* pFrame; // r31
    // s32 nEvent; // r1+0xC

    // References
    // -> struct __anon_0x26AFD* gpSystem;
    // -> static s32 gnCountMapHack;
    // -> static s32 gbFrameValid;
    // -> static s32 gbFrameBegin;
}
