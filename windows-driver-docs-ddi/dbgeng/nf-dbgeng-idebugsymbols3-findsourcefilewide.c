HRESULT FindSourceFileWide(
  [in]            ULONG  StartElement,
  [in]            PCWSTR File,
  [in]            ULONG  Flags,
  [out, optional] PULONG FoundElement,
  [out, optional] PWSTR  Buffer,
  [in]            ULONG  BufferSize,
  [out, optional] PULONG FoundSize
);