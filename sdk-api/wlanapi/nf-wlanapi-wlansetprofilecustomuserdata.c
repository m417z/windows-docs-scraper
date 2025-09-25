DWORD WlanSetProfileCustomUserData(
  [in] HANDLE      hClientHandle,
  [in] const GUID  *pInterfaceGuid,
  [in] LPCWSTR     strProfileName,
  [in] DWORD       dwDataSize,
  [in] const PBYTE pData,
       PVOID       pReserved
);