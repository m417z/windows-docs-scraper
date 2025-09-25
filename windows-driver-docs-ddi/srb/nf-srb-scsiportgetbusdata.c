SCSIPORT_API ULONG ScsiPortGetBusData(
  [in] PVOID DeviceExtension,
  [in] ULONG BusDataType,
  [in] ULONG SystemIoBusNumber,
  [in] ULONG SlotNumber,
  [in] PVOID Buffer,
  [in] ULONG Length
);