DWORD SetNtmsUIOptionsW(
  [in]  HANDLE            hSession,
  [in]  const LPNTMS_GUID lpObjectId,
  [in]  DWORD             dwType,
  [in]  DWORD             dwOperation,
  [out] LPCWSTR           lpszDestination
);