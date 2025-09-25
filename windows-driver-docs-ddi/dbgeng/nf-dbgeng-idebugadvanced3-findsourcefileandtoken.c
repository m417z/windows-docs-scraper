HRESULT FindSourceFileAndToken(
  [in]            ULONG   StartElement,
  [in]            ULONG64 ModAddr,
  [in]            PCSTR   File,
  [in]            ULONG   Flags,
  [in, optional]  PVOID   FileToken,
  [in]            ULONG   FileTokenSize,
  [out, optional] PULONG  FoundElement,
  [out, optional] PSTR    Buffer,
  [in]            ULONG   BufferSize,
  [out, optional] PULONG  FoundSize
);