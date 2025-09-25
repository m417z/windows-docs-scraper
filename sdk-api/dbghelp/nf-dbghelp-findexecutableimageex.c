HANDLE IMAGEAPI FindExecutableImageEx(
  [in]           PCSTR                   FileName,
  [in]           PCSTR                   SymbolPath,
  [out]          PSTR                    ImageFilePath,
  [in, optional] PFIND_EXE_FILE_CALLBACK Callback,
  [in, optional] PVOID                   CallerData
);