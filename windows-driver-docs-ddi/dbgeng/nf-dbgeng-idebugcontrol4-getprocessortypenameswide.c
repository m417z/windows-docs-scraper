HRESULT GetProcessorTypeNamesWide(
  [in]            ULONG  Type,
  [out, optional] PWSTR  FullNameBuffer,
  [in]            ULONG  FullNameBufferSize,
  [out, optional] PULONG FullNameSize,
  [out, optional] PWSTR  AbbrevNameBuffer,
  [in]            ULONG  AbbrevNameBufferSize,
  [out, optional] PULONG AbbrevNameSize
);