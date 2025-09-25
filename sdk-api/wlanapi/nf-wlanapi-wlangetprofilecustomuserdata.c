DWORD WlanGetProfileCustomUserData(
  [in]  HANDLE     hClientHandle,
  [in]  const GUID *pInterfaceGuid,
  [in]  LPCWSTR    strProfileName,
        PVOID      pReserved,
  [out] DWORD      *pdwDataSize,
  [out] PBYTE      *ppData
);