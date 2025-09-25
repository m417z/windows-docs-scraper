typedef enum {
  UFS_PurgeStatusIdle,
  UFS_PurgeStatusInProgress,
  UFS_PurgeStatusInterrupted,
  UFS_PurgeStatusSuccess,
  UFS_PurgeStatusQueueNotEmpty,
  UFS_PurgeStatusFailure
} UFS_PURGE_STATUS;