HRESULT WriteIo(
  [in]            ULONG   InterfaceType,
  [in]            ULONG   BusNumber,
  [in]            ULONG   AddressSpace,
  [in]            ULONG64 Offset,
  [in]            PVOID   Buffer,
  [in]            ULONG   BufferSize,
  [out, optional] PULONG  BytesWritten
);