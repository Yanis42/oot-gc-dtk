#include "dolphin/types.h"
#include "xlObject.h"
#include "xlFile.h"
#include "xlFileGCN.h"
#include "xlHeap.h"
#include "xlText.h"

#if VERSION == 3 // PZLP01
// this variable is inside xlFile.c on CE-EU
_XL_OBJECTTYPE gTypeFile = {
    "FILE",
    sizeof(tXL_FILE),
    NULL,
    (EventFunc)xlFileEvent,
};
#endif

static char* gacValidNumber = "0123456789.xXABCDEFabcdef";
static char* gacValidSymbol = "~!@#$%^&*()-=_+{}[]|\\:;'<>?,./";
static char* gacValidLabel = "ABCDEFGHIJKLMNOPQRSTUVWXYZ_abcdefghijklmnopqrstuvwxyz0123456789";

char* strchr(const char* str, int chr);

#if VERSION == 3 // PZLP01
// this function is inside xlFileGCN.c on the other versions
s32 xlFileGetSize(s32* pnSize, char* szFileName) {
    tXL_FILE* pFile;

    if (xlFileOpen(&pFile, XLFT_BINARY, szFileName)) {
        if (pnSize != NULL) {
            *pnSize = pFile->nSize;
        }

        if (!xlFileClose(&pFile)) {
            return 0;
        }

        return 1;
    }

    return 0;
}
#endif

s32 xlFileGetLine(tXL_FILE* pFile, char* acLine, s32 nSizeLine) {
    s32 iCharacter;
    char nCharacter;

    while (TRUE) {
        iCharacter = 0;

        while (iCharacter < nSizeLine && xlFileGet(pFile, &nCharacter, 1)) {
            if (nCharacter == '\n') {
                break;
            }
            if (nCharacter == '\r') {
                xlFileGet(pFile, &nCharacter, 1);
                if ((nCharacter != '\n') && !xlFileSetPosition(pFile, pFile->nOffset - 1)) {
                    return 0;
                }
                break;
            }
            acLine[iCharacter++] = nCharacter;
        }

        acLine[iCharacter] = '\0';
        pFile->nLineNumber++;
        if ((iCharacter != 0) || (nCharacter == -1)) {
            return ((iCharacter == 0) && (nCharacter == -1)) ? 0 : 1;
        }
    }
}

s32 xlTokenGetInteger(char* acToken, s32* pnValue) {
    s32 nValue;
    s32 nBase;
    s32 iToken;
    s32 bNegate;

    nValue = 0;
    iToken = 0;
    bNegate = 0;

    if ((acToken[iToken] == '+') || (acToken[iToken] == '-')) {
        bNegate = acToken[iToken++] == '-' ? 1 : 0;
    }

    if ((acToken[iToken] == '0') && ((acToken[iToken + 1] == 'X') || (acToken[iToken + 1] == 'x'))) {
        nBase = 0x10;
        iToken += 2;
    } else {
        nBase = 0xA;
    }

    while  (acToken[iToken] != '\0') {
        nValue *= nBase;
        if ((acToken[iToken] >= 'A') && (acToken[iToken] <= 'F')) {
            nValue += acToken[iToken] - '7';
        } else if ((acToken[iToken] >= 'a') && (acToken[iToken] <= 'f')) {
            nValue += acToken[iToken] - 'W';
        } else if ((acToken[iToken] >= '0') && (acToken[iToken] <= '9')) {
            nValue += acToken[iToken] - '0';
        } else {
            return 0;
        }
        iToken++;
    }

    if (bNegate != 0) {
        nValue = -nValue;
    }

    if (pnValue != NULL) {
        *pnValue = nValue;
    }

    return 1;
}

s32 xlFileSkipLine(tXL_FILE* pFile) {
    pFile->iLine = -1;
    return 1;
}

s32 xlFileGetToken(tXL_FILE* pFile, XlFileTokenType* peType, char* acToken, s32 nSizeToken) {
    char* acLine;
    s32 iLine;
    s32 iToken;
    XlFileTokenType eType;

    iToken = 0;
    eType = XLFTT_NONE;

    if (pFile->acLine == NULL) {
        pFile->iLine = -1;
        pFile->nLineNumber = 0;
        if (!xlHeapTake(&pFile->acLine, 0x101)) {
            return 0;
        }
    }

    iLine = pFile->iLine;
    acLine = pFile->acLine;

    while (eType == XLFTT_NONE) {
        if ((iLine < 0) || (iLine >= 0x100) || (acLine[iLine] == '\0')) {
            if (xlFileGetLine(pFile, acLine, 0x100)) {
                iLine = 0;
            } else {
                pFile->iLine = -1;
                return 0;
            }
        }

        while ((acLine[iLine] <= ' ') && (acLine[iLine] != '\0')) {
            iLine++;
        }

        if (acLine[iLine] != '\0') {
            if ((acLine[iLine] >= '0' && acLine[iLine] <= '9')
                || ((acLine[iLine] == '+' || acLine[iLine] == '-') && acLine[iLine + 1] >= '0' && acLine[iLine + 1] <= '9')) {
                eType = XLFTT_NUMBER;
                while (acLine[iLine] != '\0') {
                    if (iToken < nSizeToken) {
                        acToken[iToken++] = acLine[iLine];
                    }
                    iLine++;
                    if (strchr(gacValidNumber, acLine[iLine]) == NULL) {
                        break;
                    }
                }
            } else if (((acLine[iLine] >= 'A') && (acLine[iLine] <= 'Z')) 
                || (!(acLine[iLine] < 'a') && (acLine[iLine] <= 'z')) || (acLine[iLine] == '_')) {
                eType = XLFTT_LABEL;
                while (acLine[iLine] != '\0') {
                    if (iToken < nSizeToken) {
                        acToken[iToken++] = acLine[iLine];
                    }
                    iLine++;
                    if (strchr(gacValidLabel, acLine[iLine]) == NULL) {
                        break;
                    }
                }
            } else if (acLine[iLine] == '"') {
                eType = XLFTT_STRING;
                iLine++;
                while ((acLine[iLine] != '\0') && (acLine[iLine] != '"')) {
                    if (iToken < nSizeToken) {
                        acToken[iToken++] = acLine[iLine];
                    }
                    iLine++;
                }
                if (acLine[iLine] == '"') {
                    iLine++;
                }
            } else {
                if (strchr(gacValidSymbol, acLine[iLine]) == NULL) {
                    pFile->iLine = iLine;
                    return 0;
                }
                eType = XLFTT_SYMBOL;
                acToken[iToken++] = acLine[iLine++];
            }
        }
    }

    pFile->iLine = iLine;
    acToken[iToken] = 0;
    if (peType != NULL) {
        *peType = eType;
    }
    return 1;
}

s32 xlFileMatchToken(tXL_FILE* pFile, XlFileTokenType eType, char* acToken, s32 nSizeToken, char* szText) {
    XlFileTokenType eTypeToken;
    char acTokenLocal[65];

    if ((xlFileGetToken(pFile, &eTypeToken, acTokenLocal, 64) != 0) && (eType == eTypeToken) 
        && ((szText == NULL) || (xlTextMatch(acTokenLocal, szText) != 0))) {
        if (acToken != NULL) {
            if (nSizeToken < 64) {
                acTokenLocal[nSizeToken] = '\0';
            }
            if (!xlTextCopy(acToken, acTokenLocal)) {
                return 0;
            }
        }
        return 1;
    }
    return 0;
}

s32 xlFileGetLineSave(tXL_FILE* pFile, tXL_SAVE* pSave) {
    if (pSave != NULL) {
        pSave->nLineNumber = pFile->nLineNumber;
        if (!xlFileGetPosition()) {
            return 0;
        }
        return 1;
    }
    return 0;
}
