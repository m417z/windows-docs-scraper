BOOL IMAGEAPI SymEnumerateModulesW64(
  [in]           HANDLE                       hProcess,
  [in]           PSYM_ENUMMODULES_CALLBACKW64 EnumModulesCallback,
  [in, optional] PVOID                        UserContext
);