BOOL LoadStringByReference(
  [in]            DWORD  Flags,
  [in, optional]  PCWSTR Language,
  [in]            PCWSTR SourceString,
  [out, optional] PWSTR  Buffer,
  [in]            ULONG  cchBuffer,
  [in, optional]  PCWSTR Directory,
  [out, optional] PULONG pcchBufferOut
);