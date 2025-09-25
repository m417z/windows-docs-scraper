BOOL IMAGEAPI SymGetLineFromAddr(
  [in]  HANDLE         hProcess,
  [in]  DWORD          dwAddr,
  [out] PDWORD         pdwDisplacement,
  [out] PIMAGEHLP_LINE Line
);