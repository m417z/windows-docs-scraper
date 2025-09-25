NTSTATUS WheaReportHwErrorDeviceDriver(
  ULONG               ErrorSourceId,
  PDEVICE_OBJECT      DeviceObject,
  PUCHAR              ErrorData,
  ULONG               ErrorDataLength,
  LPGUID              SectionTypeGuid,
  WHEA_ERROR_SEVERITY ErrorSeverity,
  LPSTR               DeviceFriendlyName
);