BOOL IMAGEAPI SymEnumerateModules64(
  [in]           HANDLE                      hProcess,
  [in]           PSYM_ENUMMODULES_CALLBACK64 EnumModulesCallback,
  [in, optional] PVOID                       UserContext
);