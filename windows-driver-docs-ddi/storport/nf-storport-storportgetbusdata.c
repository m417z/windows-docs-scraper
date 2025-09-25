STORPORT_API ULONG StorPortGetBusData(
  [in]      PVOID DeviceExtension,
  [in]      ULONG BusDataType,
  [in]      ULONG SystemIoBusNumber,
  [in]      ULONG SlotNumber,
  [in, out] PVOID Buffer,
  [in]      ULONG Length
);