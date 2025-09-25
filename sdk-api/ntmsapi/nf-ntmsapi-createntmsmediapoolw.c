DWORD CreateNtmsMediaPoolW(
  [in]  HANDLE                hSession,
  [in]  LPCWSTR               lpPoolName,
  [in]  LPNTMS_GUID           lpMediaType,
  [in]  DWORD                 dwAction,
  [in]  LPSECURITY_ATTRIBUTES lpSecurityAttributes,
  [out] LPNTMS_GUID           lpPoolId
);