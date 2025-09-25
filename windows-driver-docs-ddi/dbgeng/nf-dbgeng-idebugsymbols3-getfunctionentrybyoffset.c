HRESULT GetFunctionEntryByOffset(
  [in]            ULONG64 Offset,
  [in]            ULONG   Flags,
  [out, optional] PVOID   Buffer,
  [in]            ULONG   BufferSize,
  [out, optional] PULONG  BufferNeeded
);