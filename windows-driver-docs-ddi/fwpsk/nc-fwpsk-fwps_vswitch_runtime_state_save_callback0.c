FWPS_VSWITCH_RUNTIME_STATE_SAVE_CALLBACK0 FwpsVswitchRuntimeStateSaveCallback0;

NTSTATUS FwpsVswitchRuntimeStateSaveCallback0(
  [in, optional] void *notifyContext,
  [in]           void *completionContext,
  [in]           FWPS_VSWITCH_EVENT_TYPE eventType,
  [in]           const NDIS_SWITCH_PARAMETERS *vSwitch,
  [in]           NDIS_SWITCH_PORT_ID portId,
                 void **runtimeState,
  [out]          SIZE_T *runtimeStateLength
)
{...}