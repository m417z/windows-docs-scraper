BOOL IMAGEAPI SymEnumerateModules(
  [in]           HANDLE                    hProcess,
  [in]           PSYM_ENUMMODULES_CALLBACK EnumModulesCallback,
  [in, optional] PVOID                     UserContext
);