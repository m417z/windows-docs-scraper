BOOL GetProcessTimes(
  [in]  HANDLE     hProcess,
  [out] LPFILETIME lpCreationTime,
  [out] LPFILETIME lpExitTime,
  [out] LPFILETIME lpKernelTime,
  [out] LPFILETIME lpUserTime
);