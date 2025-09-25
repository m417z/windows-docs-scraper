DWORD SignalObjectAndWait(
  [in] HANDLE hObjectToSignal,
  [in] HANDLE hObjectToWaitOn,
  [in] DWORD  dwMilliseconds,
  [in] BOOL   bAlertable
);