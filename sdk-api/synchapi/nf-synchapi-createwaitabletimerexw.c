HANDLE CreateWaitableTimerExW(
  [in, optional] LPSECURITY_ATTRIBUTES lpTimerAttributes,
  [in, optional] LPCWSTR               lpTimerName,
  [in]           DWORD                 dwFlags,
  [in]           DWORD                 dwDesiredAccess
);