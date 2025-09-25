BOOL WTSQuerySessionInformationW(
  [in]  HANDLE         hServer,
  [in]  DWORD          SessionId,
  [in]  WTS_INFO_CLASS WTSInfoClass,
  [out] LPWSTR         *ppBuffer,
  [out] DWORD          *pBytesReturned
);