BOOL IMAGEAPI SymEnumTypes(
  [in]           HANDLE                         hProcess,
  [in]           ULONG64                        BaseOfDll,
  [in]           PSYM_ENUMERATESYMBOLS_CALLBACK EnumSymbolsCallback,
  [in, optional] PVOID                          UserContext
);