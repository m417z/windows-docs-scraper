BOOL IMAGEAPI SymEnumSourceFiles(
  [in]           HANDLE                        hProcess,
  [in]           ULONG64                       ModBase,
  [in, optional] PCSTR                         Mask,
  [in]           PSYM_ENUMSOURCEFILES_CALLBACK cbSrcFiles,
  [in, optional] PVOID                         UserContext
);