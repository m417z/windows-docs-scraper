DWORD WlanSetProfile(
  [in]           HANDLE     hClientHandle,
  [in]           const GUID *pInterfaceGuid,
  [in]           DWORD      dwFlags,
  [in]           LPCWSTR    strProfileXml,
  [in, optional] LPCWSTR    strAllUserProfileSecurity,
  [in]           BOOL       bOverwrite,
  [in]           PVOID      pReserved,
  [out]          DWORD      *pdwReasonCode
);