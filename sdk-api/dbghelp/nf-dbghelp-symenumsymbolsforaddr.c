BOOL IMAGEAPI SymEnumSymbolsForAddr(
  [in]           HANDLE                         hProcess,
  [in]           DWORD64                        Address,
  [in]           PSYM_ENUMERATESYMBOLS_CALLBACK EnumSymbolsCallback,
  [in, optional] PVOID                          UserContext
);