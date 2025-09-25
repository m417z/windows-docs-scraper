HRESULT ReadIo(
  [in]            ULONG   InterfaceType,
  [in]            ULONG   BusNumber,
  [in]            ULONG   AddressSpace,
  [in]            ULONG64 Offset,
  [out]           PVOID   Buffer,
  [in]            ULONG   BufferSize,
  [out, optional] PULONG  BytesRead
);