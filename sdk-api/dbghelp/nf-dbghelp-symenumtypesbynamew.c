BOOL IMAGEAPI SymEnumTypesByNameW(
  [in]           HANDLE                          hProcess,
  [in]           ULONG64                         BaseOfDll,
  [in, optional] PCWSTR                          mask,
  [in]           PSYM_ENUMERATESYMBOLS_CALLBACKW EnumSymbolsCallback,
  [in]           PVOID                           UserContext
);