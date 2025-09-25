HANDLE IMAGEAPI FindExecutableImageExW(
  [in]           PCWSTR                   FileName,
  [in]           PCWSTR                   SymbolPath,
  [out]          PWSTR                    ImageFilePath,
  [in, optional] PFIND_EXE_FILE_CALLBACKW Callback,
  [in, optional] PVOID                    CallerData
);