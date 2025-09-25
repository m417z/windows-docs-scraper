typedef struct _FILE_LOCK {
  PCOMPLETE_LOCK_IRP_ROUTINE CompleteLockIrpRoutine;
  PUNLOCK_ROUTINE            UnlockRoutine;
  BOOLEAN                    FastIoIsQuestionable;
  BOOLEAN                    SpareC[3];
  PVOID                      LockInformation;
  FILE_LOCK_INFO             LastReturnedLockInfo;
  PVOID                      LastReturnedLock;
  LONG                       LockRequestsInProgress;
} FILE_LOCK;