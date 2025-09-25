BOOL IMAGEAPI SymEnumTypesW(
  [in]           HANDLE                          hProcess,
  [in]           ULONG64                         BaseOfDll,
  [in]           PSYM_ENUMERATESYMBOLS_CALLBACKW EnumSymbolsCallback,
  [in, optional] PVOID                           UserContext
);