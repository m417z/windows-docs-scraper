BOOL WTSQuerySessionInformationA(
  [in]  HANDLE         hServer,
  [in]  DWORD          SessionId,
  [in]  WTS_INFO_CLASS WTSInfoClass,
  [out] LPSTR          *ppBuffer,
  [out] DWORD          *pBytesReturned
);