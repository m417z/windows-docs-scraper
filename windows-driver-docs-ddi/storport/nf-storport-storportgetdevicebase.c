STORPORT_API PVOID StorPortGetDeviceBase(
  [in] PVOID                 HwDeviceExtension,
  [in] INTERFACE_TYPE        BusType,
  [in] ULONG                 SystemIoBusNumber,
  [in] STOR_PHYSICAL_ADDRESS IoAddress,
  [in] ULONG                 NumberOfBytes,
  [in] BOOLEAN               InIoSpace
);