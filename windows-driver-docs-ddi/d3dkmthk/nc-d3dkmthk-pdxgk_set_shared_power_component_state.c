PDXGK_SET_SHARED_POWER_COMPONENT_STATE PdxgkSetSharedPowerComponentState;

NTSTATUS PdxgkSetSharedPowerComponentState(
  PVOID DeviceHandle,
  PVOID PrivateHandle,
  ULONG ComponentIndex,
  BOOLEAN Active
)
{...}