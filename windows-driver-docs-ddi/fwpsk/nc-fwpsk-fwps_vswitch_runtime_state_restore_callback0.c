FWPS_VSWITCH_RUNTIME_STATE_RESTORE_CALLBACK0 FwpsVswitchRuntimeStateRestoreCallback0;

NTSTATUS FwpsVswitchRuntimeStateRestoreCallback0(
  [in, optional] void *notifyContext,
  [in]           void *completionContext,
  [in]           FWPS_VSWITCH_EVENT_TYPE eventType,
  [in]           const NDIS_SWITCH_PARAMETERS *vSwitch,
  [in]           NDIS_SWITCH_PORT_ID portId,
                 void *runtimeState,
  [in]           SIZE_T runtimeStateLength
)
{...}