HRESULT SearchVirtual(
  [in]  ULONG64  Offset,
  [in]  ULONG64  Length,
  [in]  PVOID    Pattern,
  [in]  ULONG    PatternSize,
  [in]  ULONG    PatternGranularity,
  [out] PULONG64 MatchOffset
);