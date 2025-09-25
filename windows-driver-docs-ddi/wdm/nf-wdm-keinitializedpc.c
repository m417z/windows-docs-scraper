VOID KeInitializeDpc(
  [out]          __drv_aliasesMem PRKDPC Dpc,
  [in]           PKDEFERRED_ROUTINE      DeferredRoutine,
  [in, optional] __drv_aliasesMem PVOID  DeferredContext
);