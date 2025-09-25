BOOL IMAGEAPI SymGetTypeFromNameW(
  [in]      HANDLE        hProcess,
  [in]      ULONG64       BaseOfDll,
  [in]      PCWSTR        Name,
  [in, out] PSYMBOL_INFOW Symbol
);