HRESULT ReadMultiByteStringVirtual(
  [in]            ULONG64 Offset,
  [in]            ULONG   MaxBytes,
  [out, optional] PSTR    Buffer,
  [in]            ULONG   BufferSize,
  [out, optional] PULONG  StringBytes
);