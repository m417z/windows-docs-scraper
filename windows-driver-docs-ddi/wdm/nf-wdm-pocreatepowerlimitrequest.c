NTSTATUS PoCreatePowerLimitRequest(
  PVOID                   *PowerLimitRequest,
  PDEVICE_OBJECT          TargetDeviceObject,
  PDEVICE_OBJECT          PolicyDeviceObject,
  PCOUNTED_REASON_CONTEXT Context
);