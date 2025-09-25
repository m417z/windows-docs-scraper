STORPORT_API BOOLEAN StorPortValidateRange(
  [in] PVOID                 HwDeviceExtension,
  [in] INTERFACE_TYPE        BusType,
       ULONG                 SystemIoBusNumber,
  [in] STOR_PHYSICAL_ADDRESS IoAddress,
  [in] ULONG                 NumberOfBytes,
  [in] BOOLEAN               InIoSpace
);