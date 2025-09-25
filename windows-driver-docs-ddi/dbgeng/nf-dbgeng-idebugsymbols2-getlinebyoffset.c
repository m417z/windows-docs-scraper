HRESULT GetLineByOffset(
  [in]            ULONG64  Offset,
  [out, optional] PULONG   Line,
  [out, optional] PSTR     FileBuffer,
  [in]            ULONG    FileBufferSize,
  [out, optional] PULONG   FileSize,
  [out, optional] PULONG64 Displacement
);