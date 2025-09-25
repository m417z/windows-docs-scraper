typedef struct _QUOTA_LIMITS {
  SIZE_T        PagedPoolLimit;
  SIZE_T        NonPagedPoolLimit;
  SIZE_T        MinimumWorkingSetSize;
  SIZE_T        MaximumWorkingSetSize;
  SIZE_T        PagefileLimit;
  LARGE_INTEGER TimeLimit;
} QUOTA_LIMITS, *PQUOTA_LIMITS;