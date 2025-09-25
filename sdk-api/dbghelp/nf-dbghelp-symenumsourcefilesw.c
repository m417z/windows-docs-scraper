BOOL IMAGEAPI SymEnumSourceFilesW(
  [in]           HANDLE                         hProcess,
  [in]           ULONG64                        ModBase,
  [in, optional] PCWSTR                         Mask,
  [in]           PSYM_ENUMSOURCEFILES_CALLBACKW cbSrcFiles,
  [in, optional] PVOID                          UserContext
);