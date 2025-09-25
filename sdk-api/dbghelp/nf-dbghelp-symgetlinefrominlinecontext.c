BOOL IMAGEAPI SymGetLineFromInlineContext(
  [in]           HANDLE           hProcess,
  [in]           DWORD64          qwAddr,
  [in]           ULONG            InlineContext,
  [in, optional] DWORD64          qwModuleBaseAddress,
  [out]          PDWORD           pdwDisplacement,
  [out]          PIMAGEHLP_LINE64 Line64
);