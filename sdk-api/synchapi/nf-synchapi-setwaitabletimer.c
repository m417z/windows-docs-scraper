BOOL SetWaitableTimer(
  [in]           HANDLE              hTimer,
  [in]           const LARGE_INTEGER *lpDueTime,
  [in]           LONG                lPeriod,
  [in, optional] PTIMERAPCROUTINE    pfnCompletionRoutine,
  [in, optional] LPVOID              lpArgToCompletionRoutine,
  [in]           BOOL                fResume
);