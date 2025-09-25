DBHLP_DEPRECIATED BOOL IMAGEAPI SymEnumerateSymbolsW(
  [in]           HANDLE                     hProcess,
  [in]           ULONG                      BaseOfDll,
  [in]           PSYM_ENUMSYMBOLS_CALLBACKW EnumSymbolsCallback,
  [in, optional] PVOID                      UserContext
);