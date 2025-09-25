HRESULT ReadUnicodeStringVirtual(
  [in]            ULONG64 Offset,
  [in]            ULONG   MaxBytes,
  [in]            ULONG   CodePage,
  [out, optional] PSTR    Buffer,
  [in]            ULONG   BufferSize,
  [out, optional] PULONG  StringBytes
);