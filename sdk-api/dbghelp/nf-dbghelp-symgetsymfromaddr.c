BOOL IMAGEAPI SymGetSymFromAddr(
  [in]            HANDLE           hProcess,
  [in]            DWORD            dwAddr,
  [out, optional] PDWORD           pdwDisplacement,
  [in, out]       PIMAGEHLP_SYMBOL Symbol
);