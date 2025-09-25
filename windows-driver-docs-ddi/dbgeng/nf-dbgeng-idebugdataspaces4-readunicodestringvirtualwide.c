HRESULT ReadUnicodeStringVirtualWide(
  [in]            ULONG64 Offset,
  [in]            ULONG   MaxBytes,
  [out, optional] PWSTR   Buffer,
  [in]            ULONG   BufferSize,
  [out, optional] PULONG  StringBytes
);