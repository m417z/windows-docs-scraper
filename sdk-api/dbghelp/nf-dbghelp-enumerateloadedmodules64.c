BOOL IMAGEAPI EnumerateLoadedModules64(
  [in]           HANDLE                         hProcess,
  [in]           PENUMLOADED_MODULES_CALLBACK64 EnumLoadedModulesCallback,
  [in, optional] PVOID                          UserContext
);