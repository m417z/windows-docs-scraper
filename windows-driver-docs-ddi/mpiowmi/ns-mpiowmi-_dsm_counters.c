typedef struct _DSM_COUNTERS {
  ULONG     PathVerifyEnabled;
  ULONG     PathVerificationPeriod;
  ULONG     PDORemovePeriod;
  ULONG     RetryCount;
  ULONG     RetryInterval;
  ULONG     Reserved32;
  ULONGLONG Reserved64;
} DSM_COUNTERS, *PDSM_COUNTERS;