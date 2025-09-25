HRESULT ReadControl(
  [in]            ULONG   Processor,
  [in]            ULONG64 Offset,
  [out]           PVOID   Buffer,
  [in]            ULONG   BufferSize,
  [out, optional] PULONG  BytesRead
);