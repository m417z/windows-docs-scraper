BOOL GetFileBandwidthReservation(
  [in]  HANDLE  hFile,
  [out] LPDWORD lpPeriodMilliseconds,
  [out] LPDWORD lpBytesPerPeriod,
  [out] LPBOOL  pDiscardable,
  [out] LPDWORD lpTransferSize,
  [out] LPDWORD lpNumOutstandingRequests
);