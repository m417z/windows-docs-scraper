BOOL IMAGEAPI SymFindFileInPathW(
  [in]           HANDLE                   hprocess,
  [in, optional] PCWSTR                   SearchPath,
  [in]           PCWSTR                   FileName,
  [in, optional] PVOID                    id,
  [in]           DWORD                    two,
  [in]           DWORD                    three,
  [in]           DWORD                    flags,
  [out]          PWSTR                    FoundFile,
  [in, optional] PFINDFILEINPATHCALLBACKW callback,
  [in, optional] PVOID                    context
);