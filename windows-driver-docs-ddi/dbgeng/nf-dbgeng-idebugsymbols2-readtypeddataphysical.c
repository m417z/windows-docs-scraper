HRESULT ReadTypedDataPhysical(
  [in]            ULONG64 Offset,
  [in]            ULONG64 Module,
  [in]            ULONG   TypeId,
  [out]           PVOID   Buffer,
  [in]            ULONG   BufferSize,
  [out, optional] PULONG  BytesRead
);