typedef struct _FILE_QUOTA_INFORMATION {
  ULONG         NextEntryOffset;
  ULONG         SidLength;
  LARGE_INTEGER ChangeTime;
  LARGE_INTEGER QuotaUsed;
  LARGE_INTEGER QuotaThreshold;
  LARGE_INTEGER QuotaLimit;
  SID           Sid;
} FILE_QUOTA_INFORMATION, *PFILE_QUOTA_INFORMATION;