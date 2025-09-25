typedef enum _STOR_SPINLOCK {
  InvalidLock,
  DpcLock,
  StartIoLock,
  InterruptLock,
  ThreadedDpcLock,
  DpcLevelLock
} STOR_SPINLOCK;