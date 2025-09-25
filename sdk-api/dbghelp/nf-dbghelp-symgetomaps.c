BOOL IMAGEAPI SymGetOmaps(
  [in]  HANDLE   hProcess,
  [in]  DWORD64  BaseOfDll,
  [out] POMAP    *OmapTo,
  [out] PDWORD64 cOmapTo,
  [out] POMAP    *OmapFrom,
  [out] PDWORD64 cOmapFrom
);