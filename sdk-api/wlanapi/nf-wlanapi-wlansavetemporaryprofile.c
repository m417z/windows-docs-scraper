DWORD WlanSaveTemporaryProfile(
  [in]           HANDLE     hClientHandle,
  [in]           const GUID *pInterfaceGuid,
  [in]           LPCWSTR    strProfileName,
  [in, optional] LPCWSTR    strAllUserProfileSecurity,
  [in]           DWORD      dwFlags,
  [in]           BOOL       bOverWrite,
                 PVOID      pReserved
);