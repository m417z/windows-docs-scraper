BOOL IMAGEAPI SymGetTypeFromName(
  [in]      HANDLE       hProcess,
  [in]      ULONG64      BaseOfDll,
  [in]      PCSTR        Name,
  [in, out] PSYMBOL_INFO Symbol
);