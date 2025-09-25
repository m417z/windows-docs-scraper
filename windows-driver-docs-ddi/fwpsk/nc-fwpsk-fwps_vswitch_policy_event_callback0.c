FWPS_VSWITCH_POLICY_EVENT_CALLBACK0 FwpsVswitchPolicyEventCallback0;

NTSTATUS FwpsVswitchPolicyEventCallback0(
  [in, optional] void *notifyContext,
  [in]           void *completionContext,
  [in]           FWPS_VSWITCH_EVENT_TYPE eventType,
  [in]           const NDIS_SWITCH_PARAMETERS *vSwitch,
  [in, optional] const NDIS_SWITCH_PORT_PROPERTY_PARAMETERS *vSwitchPortProperty,
  [in, optional] const NDIS_SWITCH_PORT_PROPERTY_DELETE_PARAMETERS *vSwitchPortPropertyDelete
)
{...}