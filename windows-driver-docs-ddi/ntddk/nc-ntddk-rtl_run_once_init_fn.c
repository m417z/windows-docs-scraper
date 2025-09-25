ULONG /* LOGICAL */
NTAPI
RTL_RUN_ONCE_INIT_FN (
    _Inout_ PRTL_RUN_ONCE RunOnce,
    _Inout_opt_ PVOID Parameter,
    _Inout_opt_ PVOID *Context
  );

typedef RTL_RUN_ONCE_INIT_FN *PRTL_RUN_ONCE_INIT_FN;