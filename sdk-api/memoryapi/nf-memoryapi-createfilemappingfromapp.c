HANDLE CreateFileMappingFromApp(
  [in]           HANDLE               hFile,
  [in, optional] PSECURITY_ATTRIBUTES SecurityAttributes,
  [in]           ULONG                PageProtection,
  [in]           ULONG64              MaximumSize,
  [in, optional] PCWSTR               Name
);