BOOL IMAGEAPI SymSearch(
  [in]           HANDLE                         hProcess,
  [in]           ULONG64                        BaseOfDll,
  [in, optional] DWORD                          Index,
  [in, optional] DWORD                          SymTag,
  [in, optional] PCSTR                          Mask,
  [in, optional] DWORD64                        Address,
  [in]           PSYM_ENUMERATESYMBOLS_CALLBACK EnumSymbolsCallback,
  [in, optional] PVOID                          UserContext,
  [in]           DWORD                          Options
);