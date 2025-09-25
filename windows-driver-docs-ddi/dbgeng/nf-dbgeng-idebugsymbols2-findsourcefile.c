HRESULT FindSourceFile(
  [in]            ULONG  StartElement,
  [in]            PCSTR  File,
  [in]            ULONG  Flags,
  [out, optional] PULONG FoundElement,
  [out, optional] PSTR   Buffer,
  [in]            ULONG  BufferSize,
  [out, optional] PULONG FoundSize
);