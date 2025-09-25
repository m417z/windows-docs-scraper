BOOL IMAGEAPI SymEnumSymbolsExW(
  [in]           HANDLE                          hProcess,
  [in]           ULONG64                         BaseOfDll,
  [in, optional] PCWSTR                          Mask,
  [in]           PSYM_ENUMERATESYMBOLS_CALLBACKW EnumSymbolsCallback,
  [in, optional] PVOID                           UserContext,
  [in]           DWORD                           Options
);