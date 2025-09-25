BOOL IMAGEAPI SymGetLineFromNameW64(
  [in]           HANDLE            hProcess,
  [in, optional] PCWSTR            ModuleName,
  [in, optional] PCWSTR            FileName,
  [in]           DWORD             dwLineNumber,
  [out]          PLONG             plDisplacement,
  [in, out]      PIMAGEHLP_LINEW64 Line
);