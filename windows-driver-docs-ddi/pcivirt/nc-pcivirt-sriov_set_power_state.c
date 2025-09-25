SRIOV_SET_POWER_STATE SriovSetPowerState;

NTSTATUS SriovSetPowerState(
  [in] PVOID Context,
  [in] USHORT VfIndex,
  [in] DEVICE_POWER_STATE PowerState,
  [in] BOOLEAN Wake
)
{...}