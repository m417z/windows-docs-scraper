HRESULT SearchVirtual2(
  [in]  ULONG64  Offset,
  [in]  ULONG64  Length,
  [in]  ULONG    Flags,
  [in]  PVOID    Pattern,
  [in]  ULONG    PatternSize,
  [in]  ULONG    PatternGranularity,
  [out] PULONG64 MatchOffset
);