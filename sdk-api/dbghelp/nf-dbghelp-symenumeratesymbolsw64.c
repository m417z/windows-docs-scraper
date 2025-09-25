DBHLP_DEPRECIATED BOOL IMAGEAPI SymEnumerateSymbolsW64(
  [in]           HANDLE                       hProcess,
  [in]           ULONG64                      BaseOfDll,
  [in]           PSYM_ENUMSYMBOLS_CALLBACK64W EnumSymbolsCallback,
  [in, optional] PVOID                        UserContext
);