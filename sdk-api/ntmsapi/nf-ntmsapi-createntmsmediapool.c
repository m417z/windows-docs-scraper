DWORD CreateNtmsMediaPool(
  [in]  HANDLE                hSession,
  [in]  LPCTSTR               lpPoolName,
  [in]  LPNTMS_GUID           lpMediaType,
  [in]  DWORD                 dwAction,
  [in]  LPSECURITY_ATTRIBUTES lpSecurityAttributes,
  [out] LPNTMS_GUID           lpPoolId
);