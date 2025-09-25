DXGKDDI_SET_POWER_STATE DxgkddiSetPowerState;

NTSTATUS DxgkddiSetPowerState(
  [in] IN_CONST_PVOID MiniportDeviceContext,
  [in] IN_ULONG DeviceUid,
  [in] IN_DEVICE_POWER_STATE DevicePowerState,
  [in] IN_POWER_ACTION ActionType
)
{...}