FWPS_VSWITCH_LIFETIME_EVENT_CALLBACK0 FwpsVswitchLifetimeEventCallback0;

NTSTATUS FwpsVswitchLifetimeEventCallback0(
  [in, optional] void *notifyContext,
  [in]           FWPS_VSWITCH_EVENT_TYPE eventType,
  [in]           const NDIS_SWITCH_PARAMETERS *vSwitch,
  [in, optional] const NDIS_SWITCH_PORT_ARRAY *vSwitchPorts,
  [in, optional] const NDIS_SWITCH_NIC_ARRAY *vSwitchInterfaces
)
{...}