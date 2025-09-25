ULONG StorPortGetDeviceBase2(
  PVOID                 HwDeviceExtension,
  INTERFACE_TYPE        BusType,
  ULONG                 SystemIoBusNumber,
  STOR_PHYSICAL_ADDRESS Address,
  ULONG                 NumberOfBytes,
  BOOLEAN               InIoSpace,
  ULONG                 Flags,
  PVOID                 *BaseAddress
);