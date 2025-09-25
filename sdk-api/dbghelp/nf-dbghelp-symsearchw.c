BOOL IMAGEAPI SymSearchW(
  [in]           HANDLE                          hProcess,
  [in]           ULONG64                         BaseOfDll,
  [in, optional] DWORD                           Index,
  [in, optional] DWORD                           SymTag,
  [in, optional] PCWSTR                          Mask,
  [in, optional] DWORD64                         Address,
  [in]           PSYM_ENUMERATESYMBOLS_CALLBACKW EnumSymbolsCallback,
  [in, optional] PVOID                           UserContext,
  [in]           DWORD                           Options
);