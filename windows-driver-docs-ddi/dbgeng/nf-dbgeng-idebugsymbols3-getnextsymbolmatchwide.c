HRESULT GetNextSymbolMatchWide(
  [in]            ULONG64  Handle,
  [out, optional] PWSTR    Buffer,
  [in]            ULONG    BufferSize,
  [out, optional] PULONG   MatchSize,
  [out, optional] PULONG64 Offset
);