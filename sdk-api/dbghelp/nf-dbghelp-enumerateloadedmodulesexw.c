BOOL IMAGEAPI EnumerateLoadedModulesExW(
  [in]           HANDLE                          hProcess,
  [in]           PENUMLOADED_MODULES_CALLBACKW64 EnumLoadedModulesCallback,
  [in, optional] PVOID                           UserContext
);