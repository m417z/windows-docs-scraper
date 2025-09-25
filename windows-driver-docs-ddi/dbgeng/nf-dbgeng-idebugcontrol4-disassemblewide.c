HRESULT DisassembleWide(
  [in]            ULONG64  Offset,
  [in]            ULONG    Flags,
  [out, optional] PWSTR    Buffer,
  [in]            ULONG    BufferSize,
  [out, optional] PULONG   DisassemblySize,
  [out]           PULONG64 EndOffset
);