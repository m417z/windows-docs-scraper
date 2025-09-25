DWORD CreateNtmsMediaPoolA(
  [in]  HANDLE                hSession,
  [in]  LPCSTR                lpPoolName,
  [in]  LPNTMS_GUID           lpMediaType,
  [in]  DWORD                 dwAction,
  [in]  LPSECURITY_ATTRIBUTES lpSecurityAttributes,
  [out] LPNTMS_GUID           lpPoolId
);