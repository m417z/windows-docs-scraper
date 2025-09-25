BOOL GetThreadTimes(
  [in]  HANDLE     hThread,
  [out] LPFILETIME lpCreationTime,
  [out] LPFILETIME lpExitTime,
  [out] LPFILETIME lpKernelTime,
  [out] LPFILETIME lpUserTime
);