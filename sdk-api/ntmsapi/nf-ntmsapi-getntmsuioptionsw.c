DWORD GetNtmsUIOptionsW(
  [in]      HANDLE            hSession,
  [in]      const LPNTMS_GUID lpObjectId,
  [in]      DWORD             dwType,
  [out]     LPWSTR            lpszDestination,
  [in, out] LPDWORD           lpdwBufSize
);