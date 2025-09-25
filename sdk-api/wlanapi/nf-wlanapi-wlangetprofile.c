DWORD WlanGetProfile(
  [in]                HANDLE     hClientHandle,
  [in]                const GUID *pInterfaceGuid,
  [in]                LPCWSTR    strProfileName,
  [in]                PVOID      pReserved,
  [out]               LPWSTR     *pstrProfileXml,
  [in, out, optional] DWORD      *pdwFlags,
  [out, optional]     DWORD      *pdwGrantedAccess
);