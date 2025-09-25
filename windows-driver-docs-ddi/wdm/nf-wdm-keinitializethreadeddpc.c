VOID KeInitializeThreadedDpc(
  [out]          PRKDPC             Dpc,
  [in]           PKDEFERRED_ROUTINE DeferredRoutine,
  [in, optional] PVOID              DeferredContext
);