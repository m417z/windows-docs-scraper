HANDLE IMAGEAPI SymFindDebugInfoFileW(
  [in]           HANDLE                     hProcess,
  [in]           PCWSTR                     FileName,
  [out]          PWSTR                      DebugFilePath,
  [in, optional] PFIND_DEBUG_FILE_CALLBACKW Callback,
  [in, optional] PVOID                      CallerData
);