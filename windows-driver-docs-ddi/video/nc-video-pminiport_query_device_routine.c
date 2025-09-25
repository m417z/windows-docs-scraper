PMINIPORT_QUERY_DEVICE_ROUTINE PminiportQueryDeviceRoutine;

VP_STATUS PminiportQueryDeviceRoutine(
  PVOID HwDeviceExtension,
  PVOID Context,
  VIDEO_DEVICE_DATA_TYPE DeviceDataType,
  PVOID Identifier,
  ULONG IdentiferLength,
  PVOID ConfigurationData,
  ULONG ConfigurationDataLength,
  PVOID ComponentInformation,
  ULONG ComponentInformationLength
)
{...}