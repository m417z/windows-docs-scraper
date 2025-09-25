HRESULT GetLineByInlineContextWide(
  [in]            ULONG64  Offset,
  [in]            ULONG    InlineContext,
  [out, optional] PULONG   Line,
  [out]           PWSTR    FileBuffer,
  [in]            ULONG    FileBufferSize,
  [out, optional] PULONG   FileSize,
  [out, optional] PULONG64 Displacement
);