typedef struct _CC_DIRTY_PAGES_INFO {
  ULONG    Version;
  LONGLONG DirtyPageThreshold;
  LONGLONG DirtyPageTarget;
  LONGLONG CleanLockedCachedPagesThreshold;
  LONGLONG CleanLockedCachedPagesTarget;
  LONGLONG CurrentDirtyPages;
  LONGLONG CurrentCleanLockedCachedPages;
  LONGLONG CurrentPagesQueuedForWriting;
} CC_DIRTY_PAGES_INFO, *PCC_DIRTY_PAGES_INFO;