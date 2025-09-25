BOOL IMAGEAPI SymGetSymFromAddr64(
  [in]            HANDLE             hProcess,
  [in]            DWORD64            qwAddr,
  [out, optional] PDWORD64           pdwDisplacement,
  [in, out]       PIMAGEHLP_SYMBOL64 Symbol
);