BOOL IMAGEAPI SymFromTokenW(
  [in]      HANDLE        hProcess,
  [in]      DWORD64       Base,
  [in]      DWORD         Token,
  [in, out] PSYMBOL_INFOW Symbol
);