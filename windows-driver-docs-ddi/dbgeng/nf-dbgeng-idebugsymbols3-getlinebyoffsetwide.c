HRESULT GetLineByOffsetWide(
  [in]            ULONG64  Offset,
  [out, optional] PULONG   Line,
  [out, optional] PWSTR    FileBuffer,
  [in]            ULONG    FileBufferSize,
  [out, optional] PULONG   FileSize,
  [out, optional] PULONG64 Displacement
);