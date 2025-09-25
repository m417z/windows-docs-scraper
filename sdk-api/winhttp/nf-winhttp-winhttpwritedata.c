WINHTTPAPI BOOL WinHttpWriteData(
  [in]  HINTERNET hRequest,
  [in]  LPCVOID   lpBuffer,
  [in]  DWORD     dwNumberOfBytesToWrite,
  [out] LPDWORD   lpdwNumberOfBytesWritten
);