HRESULT GetSourceFileInformationWide(
  [in]            ULONG   Which,
  [in]            PWSTR   SourceFile,
  [in]            ULONG64 Arg64,
  [in]            ULONG   Arg32,
  [out, optional] PVOID   Buffer,
  [in]            ULONG   BufferSize,
  [out, optional] PULONG  InfoSize
);