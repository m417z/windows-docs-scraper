HANDLE IMAGEAPI SymFindDebugInfoFile(
  [in]           HANDLE                    hProcess,
  [in]           PCSTR                     FileName,
  [out]          PSTR                      DebugFilePath,
  [in, optional] PFIND_DEBUG_FILE_CALLBACK Callback,
  [in, optional] PVOID                     CallerData
);