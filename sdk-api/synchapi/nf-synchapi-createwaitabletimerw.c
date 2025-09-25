HANDLE CreateWaitableTimerW(
  [in, optional] LPSECURITY_ATTRIBUTES lpTimerAttributes,
  [in]           BOOL                  bManualReset,
  [in, optional] LPCWSTR               lpTimerName
);