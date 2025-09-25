HRESULT OutputDisassemblyLines(
  [in]            ULONG    OutputControl,
  [in]            ULONG    PreviousLines,
  [in]            ULONG    TotalLines,
  [in]            ULONG64  Offset,
  [in]            ULONG    Flags,
  [out, optional] PULONG   OffsetLine,
  [out, optional] PULONG64 StartOffset,
  [out, optional] PULONG64 EndOffset,
  [out, optional] PULONG64 LineOffsets
);