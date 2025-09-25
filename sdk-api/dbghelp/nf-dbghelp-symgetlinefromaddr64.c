BOOL IMAGEAPI SymGetLineFromAddr64(
  [in]  HANDLE           hProcess,
  [in]  DWORD64          qwAddr,
  [out] PDWORD           pdwDisplacement,
  [out] PIMAGEHLP_LINE64 Line64
);