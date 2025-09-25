BOOL IMAGEAPI SymGetLineFromAddrW64(
  [in]  HANDLE            hProcess,
  [in]  DWORD64           dwAddr,
  [out] PDWORD            pdwDisplacement,
  [out] PIMAGEHLP_LINEW64 Line
);