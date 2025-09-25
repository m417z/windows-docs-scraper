typedef struct _NTMS_MEDIAPOOLINFORMATION {
  DWORD     PoolType;
  NTMS_GUID MediaType;
  NTMS_GUID Parent;
  DWORD     AllocationPolicy;
  DWORD     DeallocationPolicy;
  DWORD     dwMaxAllocates;
  DWORD     dwNumberOfPhysicalMedia;
  DWORD     dwNumberOfLogicalMedia;
  DWORD     dwNumberOfMediaPools;
} NTMS_MEDIAPOOLINFORMATION;