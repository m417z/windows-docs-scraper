BOOL IMAGEAPI SymEnumTypesByName(
  [in]           HANDLE                         hProcess,
  [in]           ULONG64                        BaseOfDll,
  [in, optional] PCSTR                          mask,
  [in]           PSYM_ENUMERATESYMBOLS_CALLBACK EnumSymbolsCallback,
  [in]           PVOID                          UserContext
);