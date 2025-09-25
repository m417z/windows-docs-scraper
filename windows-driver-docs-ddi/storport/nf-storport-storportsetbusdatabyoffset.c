STORPORT_API ULONG StorPortSetBusDataByOffset(
  [in] PVOID DeviceExtension,
  [in] ULONG BusDataType,
  [in] ULONG SystemIoBusNumber,
  [in] ULONG SlotNumber,
  [in] PVOID Buffer,
  [in] ULONG Offset,
  [in] ULONG Length
);