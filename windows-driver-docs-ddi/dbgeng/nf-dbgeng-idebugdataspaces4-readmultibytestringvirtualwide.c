HRESULT ReadMultiByteStringVirtualWide(
  [in]            ULONG64 Offset,
  [in]            ULONG   MaxBytes,
  [in]            ULONG   CodePage,
  [out, optional] PWSTR   Buffer,
  [in]            ULONG   BufferSize,
  [out, optional] PULONG  StringBytes
);