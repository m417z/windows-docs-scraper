DBHLP_DEPRECIATED BOOL IMAGEAPI SymEnumerateSymbols64(
  [in]           HANDLE                      hProcess,
  [in]           ULONG64                     BaseOfDll,
  [in]           PSYM_ENUMSYMBOLS_CALLBACK64 EnumSymbolsCallback,
  [in, optional] PVOID                       UserContext
);