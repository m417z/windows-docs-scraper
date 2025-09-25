HRESULT WriteTypedDataPhysical(
  [in]            ULONG64 Offset,
  [in]            ULONG64 Module,
  [in]            ULONG   TypeId,
  [in]            PVOID   Buffer,
  [in]            ULONG   BufferSize,
  [out, optional] PULONG  BytesWritten
);