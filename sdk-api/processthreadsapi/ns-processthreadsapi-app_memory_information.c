typedef struct _APP_MEMORY_INFORMATION {
  ULONG64 AvailableCommit;
  ULONG64 PrivateCommitUsage;
  ULONG64 PeakPrivateCommitUsage;
  ULONG64 TotalCommitUsage;
} APP_MEMORY_INFORMATION, *PAPP_MEMORY_INFORMATION;