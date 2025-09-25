typedef enum RealTimeStylusLockType {
  RTSLT_ObjLock = 0x1,
  RTSLT_SyncEventLock = 0x2,
  RTSLT_AsyncEventLock = 0x4,
  RTSLT_ExcludeCallback = 0x8,
  RTSLT_SyncObjLock = 0xb,
  RTSLT_AsyncObjLock = 0xd
} ;