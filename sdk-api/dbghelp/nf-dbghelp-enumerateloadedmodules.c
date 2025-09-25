BOOL IMAGEAPI EnumerateLoadedModules(
  [in]           HANDLE                       hProcess,
  [in]           PENUMLOADED_MODULES_CALLBACK EnumLoadedModulesCallback,
  [in, optional] PVOID                        UserContext
);