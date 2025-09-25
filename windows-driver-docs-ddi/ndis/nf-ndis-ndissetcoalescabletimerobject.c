BOOLEAN NdisSetCoalescableTimerObject(
  [in]           NDIS_HANDLE   TimerObject,
  [in]           LARGE_INTEGER DueTime,
  [in, optional] LONG          MillisecondsPeriod,
  [in, optional] PVOID         FunctionContext,
  [in, optional] ULONG         Tolerance
);