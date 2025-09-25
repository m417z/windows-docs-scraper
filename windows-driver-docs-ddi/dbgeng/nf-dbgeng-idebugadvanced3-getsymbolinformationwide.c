HRESULT GetSymbolInformationWide(
  [in]            ULONG   Which,
  [in]            ULONG64 Arg64,
  [in]            ULONG   Arg32,
  [out, optional] PVOID   Buffer,
  [in]            ULONG   BufferSize,
  [out, optional] PULONG  InfoSize,
  [out, optional] PWSTR   StringBuffer,
  [in]            ULONG   StringBufferSize,
  [out, optional] PULONG  StringSize
);