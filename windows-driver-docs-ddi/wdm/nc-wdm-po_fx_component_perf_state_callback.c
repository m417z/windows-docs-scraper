PO_FX_COMPONENT_PERF_STATE_CALLBACK PoFxComponentPerfStateCallback;

VOID PoFxComponentPerfStateCallback(
  [in] PVOID Context,
  [in] ULONG Component,
  [in] BOOLEAN Succeeded,
  [in] PVOID RequestContext
)
{...}