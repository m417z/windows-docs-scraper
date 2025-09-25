BOOL IMAGEAPI SymEnumSymbols(
  [in]           HANDLE                         hProcess,
  [in]           ULONG64                        BaseOfDll,
  [in, optional] PCSTR                          Mask,
  [in]           PSYM_ENUMERATESYMBOLS_CALLBACK EnumSymbolsCallback,
  [in, optional] PVOID                          UserContext
);