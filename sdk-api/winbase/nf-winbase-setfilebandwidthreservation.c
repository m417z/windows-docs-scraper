BOOL SetFileBandwidthReservation(
  [in]  HANDLE  hFile,
  [in]  DWORD   nPeriodMilliseconds,
  [in]  DWORD   nBytesPerPeriod,
  [in]  BOOL    bDiscardable,
  [out] LPDWORD lpTransferSize,
  [out] LPDWORD lpNumOutstandingRequests
);