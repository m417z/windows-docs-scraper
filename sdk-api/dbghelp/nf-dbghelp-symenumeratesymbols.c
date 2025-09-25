DBHLP_DEPRECIATED BOOL IMAGEAPI SymEnumerateSymbols(
  [in]           HANDLE                    hProcess,
  [in]           ULONG                     BaseOfDll,
  [in]           PSYM_ENUMSYMBOLS_CALLBACK EnumSymbolsCallback,
  [in, optional] PVOID                     UserContext
);