BOOL IMAGEAPI SymFromAddr(
  [in]            HANDLE       hProcess,
  [in]            DWORD64      Address,
  [out, optional] PDWORD64     Displacement,
  [in, out]       PSYMBOL_INFO Symbol
);