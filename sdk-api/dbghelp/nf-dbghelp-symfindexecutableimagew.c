HANDLE IMAGEAPI SymFindExecutableImageW(
  [in]  HANDLE                   hProcess,
  [in]  PCWSTR                   FileName,
  [out] PWSTR                    ImageFilePath,
  [in]  PFIND_EXE_FILE_CALLBACKW Callback,
  [in]  PVOID                    CallerData
);