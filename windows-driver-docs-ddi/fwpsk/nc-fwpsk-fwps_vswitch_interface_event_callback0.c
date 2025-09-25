FWPS_VSWITCH_INTERFACE_EVENT_CALLBACK0 FwpsVswitchInterfaceEventCallback0;

NTSTATUS FwpsVswitchInterfaceEventCallback0(
  [in, optional] void *notifyContext,
  [in]           void *completionContext,
  [in]           FWPS_VSWITCH_EVENT_TYPE eventType,
  [in]           const NDIS_SWITCH_PARAMETERS *vSwitch,
  [in]           const NDIS_SWITCH_NIC_PARAMETERS *vSwitchNic
)
{...}