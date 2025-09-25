FWPS_VSWITCH_PORT_EVENT_CALLBACK0 FwpsVswitchPortEventCallback0;

NTSTATUS FwpsVswitchPortEventCallback0(
  [in, optional] void *notifyContext,
  [in]           void *completionContext,
  [in]           FWPS_VSWITCH_EVENT_TYPE eventType,
  [in]           const NDIS_SWITCH_PARAMETERS *vSwitch,
  [in]           const NDIS_SWITCH_PORT_PARAMETERS *vSwitchPort
)
{...}