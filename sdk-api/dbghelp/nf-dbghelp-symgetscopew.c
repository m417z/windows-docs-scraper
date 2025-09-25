BOOL IMAGEAPI SymGetScopeW(
  [in]      HANDLE        hProcess,
  [in]      ULONG64       BaseOfDll,
  [in]      DWORD         Index,
  [in, out] PSYMBOL_INFOW Symbol
);