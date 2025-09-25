PULONG PoRegisterDeviceForIdleDetection(
  [in] PDEVICE_OBJECT     DeviceObject,
  [in] ULONG              ConservationIdleTime,
  [in] ULONG              PerformanceIdleTime,
  [in] DEVICE_POWER_STATE State
);