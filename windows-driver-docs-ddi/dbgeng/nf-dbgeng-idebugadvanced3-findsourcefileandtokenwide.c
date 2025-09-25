HRESULT FindSourceFileAndTokenWide(
  [in]            ULONG   StartElement,
  [in]            ULONG64 ModAddr,
  [in]            PCWSTR  File,
  [in]            ULONG   Flags,
  [in, optional]  PVOID   FileToken,
  [in]            ULONG   FileTokenSize,
  [out, optional] PULONG  FoundElement,
  [out, optional] PWSTR   Buffer,
  [in]            ULONG   BufferSize,
  [out, optional] PULONG  FoundSize
);