DWORD GetNtmsUIOptionsA(
  [in]      HANDLE            hSession,
  [in]      const LPNTMS_GUID lpObjectId,
  [in]      DWORD             dwType,
  [out]     LPSTR             lpszDestination,
  [in, out] LPDWORD           lpdwBufSize
);