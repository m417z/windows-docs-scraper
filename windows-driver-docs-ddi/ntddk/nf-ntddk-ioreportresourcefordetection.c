NTSTATUS IoReportResourceForDetection(
  [in]           PDRIVER_OBJECT    DriverObject,
  [in, optional] PCM_RESOURCE_LIST DriverList,
  [in, optional] ULONG             DriverListSize,
  [in, optional] PDEVICE_OBJECT    DeviceObject,
  [in, optional] PCM_RESOURCE_LIST DeviceList,
  [in, optional] ULONG             DeviceListSize,
  [out]          PBOOLEAN          ConflictDetected
);