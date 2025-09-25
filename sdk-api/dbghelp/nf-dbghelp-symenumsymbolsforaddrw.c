BOOL IMAGEAPI SymEnumSymbolsForAddrW(
  [in]           HANDLE                          hProcess,
  [in]           DWORD64                         Address,
  [in]           PSYM_ENUMERATESYMBOLS_CALLBACKW EnumSymbolsCallback,
  [in, optional] PVOID                           UserContext
);