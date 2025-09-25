BOOL IMAGEAPI EnumerateLoadedModulesW64(
  [in]           HANDLE                          hProcess,
  [in]           PENUMLOADED_MODULES_CALLBACKW64 EnumLoadedModulesCallback,
  [in, optional] PVOID                           UserContext
);