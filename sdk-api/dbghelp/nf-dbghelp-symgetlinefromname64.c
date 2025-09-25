BOOL IMAGEAPI SymGetLineFromName64(
  [in]           HANDLE           hProcess,
  [in, optional] PCSTR            ModuleName,
  [in, optional] PCSTR            FileName,
  [in]           DWORD            dwLineNumber,
  [out]          PLONG            plDisplacement,
  [in, out]      PIMAGEHLP_LINE64 Line
);