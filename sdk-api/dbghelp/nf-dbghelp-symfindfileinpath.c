BOOL IMAGEAPI SymFindFileInPath(
  [in]           HANDLE                  hprocess,
  [in, optional] PCSTR                   SearchPath,
  [in]           PCSTR                   FileName,
  [in, optional] PVOID                   id,
  [in]           DWORD                   two,
  [in]           DWORD                   three,
  [in]           DWORD                   flags,
  [out]          PSTR                    FoundFile,
  [in, optional] PFINDFILEINPATHCALLBACK callback,
  [in, optional] PVOID                   context
);