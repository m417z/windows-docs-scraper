HANDLE IMAGEAPI FindDebugInfoFileExW(
  [in]           PCWSTR                     FileName,
  [in]           PCWSTR                     SymbolPath,
  [out]          PWSTR                      DebugFilePath,
  [in, optional] PFIND_DEBUG_FILE_CALLBACKW Callback,
  [in, optional] PVOID                      CallerData
);