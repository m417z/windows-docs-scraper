SCSIPORT_API BOOLEAN ScsiPortValidateRange(
  [in] PVOID                 HwDeviceExtension,
  [in] INTERFACE_TYPE        BusType,
  [in] ULONG                 SystemIoBusNumber,
  [in] SCSI_PHYSICAL_ADDRESS IoAddress,
  [in] ULONG                 NumberOfBytes,
  [in] BOOLEAN               InIoSpace
);