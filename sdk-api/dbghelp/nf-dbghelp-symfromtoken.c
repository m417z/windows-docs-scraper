BOOL IMAGEAPI SymFromToken(
  [in]      HANDLE       hProcess,
  [in]      DWORD64      Base,
  [in]      DWORD        Token,
  [in, out] PSYMBOL_INFO Symbol
);