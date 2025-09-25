BOOL IMAGEAPI SymFromAddrW(
  [in]            HANDLE        hProcess,
  [in]            DWORD64       Address,
  [out, optional] PDWORD64      Displacement,
  [in, out]       PSYMBOL_INFOW Symbol
);