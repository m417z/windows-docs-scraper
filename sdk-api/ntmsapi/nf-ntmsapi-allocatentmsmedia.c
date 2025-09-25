DWORD AllocateNtmsMedia(
  [in]  HANDLE                        hSession,
  [in]  LPNTMS_GUID                   lpMediaPool,
  [in]  LPNTMS_GUID                   lpPartition,
  [out] LPNTMS_GUID                   lpMediaId,
  [in]  DWORD                         dwOptions,
  [in]  DWORD                         dwTimeout,
  [out] LPNTMS_ALLOCATION_INFORMATION lpAllocateInformation
);