HANDLE IMAGEAPI FindDebugInfoFileEx(
  [in]           PCSTR                     FileName,
  [in]           PCSTR                     SymbolPath,
  [out]          PSTR                      DebugFilePath,
  [in, optional] PFIND_DEBUG_FILE_CALLBACK Callback,
  [in, optional] PVOID                     CallerData
);