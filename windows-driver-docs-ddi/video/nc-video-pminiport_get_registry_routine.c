PMINIPORT_GET_REGISTRY_ROUTINE PminiportGetRegistryRoutine;

VP_STATUS PminiportGetRegistryRoutine(
  PVOID HwDeviceExtension,
  PVOID Context,
  PWSTR ValueName,
  PVOID ValueData,
  ULONG ValueLength
)
{...}