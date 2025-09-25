HRESULT GetNextSymbolMatch(
  [in]            ULONG64  Handle,
  [out, optional] PSTR     Buffer,
  [in]            ULONG    BufferSize,
  [out, optional] PULONG   MatchSize,
  [out, optional] PULONG64 Offset
);