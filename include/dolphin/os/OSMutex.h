#ifndef _DOLPHIN_OSMUTEX
#define _DOLPHIN_OSMUTEX

#include "dolphin/os/OSThread.h"
#include "dolphin/types.h"

#ifdef __cplusplus
extern "C" {
#endif

struct OSMutex {
    OSThreadQueue queue;
    OSThread* thread; // the current owner
    s32 count; // lock count
    OSMutexLink link; // for OSThread.queueMutex
};

struct OSCond {
    OSThreadQueue queue;
};

void OSInitMutex(OSMutex* mutex);
void OSLockMutex(OSMutex* mutex);
void __OSUnlockAllMutex(OSThread* thread);
void OSUnlockMutex(OSMutex* mutex);
bool OSTryLockMutex(OSMutex* mutex);
void OSInitCond(OSCond* cond);
void OSWaitCond(OSCond* cond, OSMutex* mutex);
void OSSignalCond(OSCond* cond);

#ifdef __cplusplus
}
#endif

#endif // _DOLPHIN_OSMUTEX
