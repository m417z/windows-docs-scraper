VOID PoFxIssueComponentPerfStateChangeMultiple(
  [in] POHANDLE                   Handle,
  [in] ULONG                      Flags,
  [in] ULONG                      Component,
  [in] ULONG                      PerfChangesCount,
  [in] PO_FX_PERF_STATE_CHANGE [] PerfChanges,
  [in] PVOID                      Context
);