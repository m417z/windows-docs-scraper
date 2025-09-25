BOOL SetWaitableTimerEx(
  [in] HANDLE              hTimer,
  [in] const LARGE_INTEGER *lpDueTime,
  [in] LONG                lPeriod,
  [in] PTIMERAPCROUTINE    pfnCompletionRoutine,
  [in] LPVOID              lpArgToCompletionRoutine,
  [in] PREASON_CONTEXT     WakeContext,
  [in] ULONG               TolerableDelay
);