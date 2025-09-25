HRESULT ReadPhysical2(
  [in]            ULONG64 Offset,
  [in]            ULONG   Flags,
  [out]           PVOID   Buffer,
  [in]            ULONG   BufferSize,
  [out, optional] PULONG  BytesRead
);