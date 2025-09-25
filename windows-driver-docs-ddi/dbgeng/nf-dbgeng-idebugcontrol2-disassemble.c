HRESULT Disassemble(
  [in]            ULONG64  Offset,
  [in]            ULONG    Flags,
  [out, optional] PSTR     Buffer,
  [in]            ULONG    BufferSize,
  [out, optional] PULONG   DisassemblySize,
  [out]           PULONG64 EndOffset
);