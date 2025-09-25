HRESULT ReadBusData(
  [in]            ULONG  BusDataType,
  [in]            ULONG  BusNumber,
  [in]            ULONG  SlotNumber,
  [in]            ULONG  Offset,
  [out]           PVOID  Buffer,
  [in]            ULONG  BufferSize,
  [out, optional] PULONG BytesRead
);