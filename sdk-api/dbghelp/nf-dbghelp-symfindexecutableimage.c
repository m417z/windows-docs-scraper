HANDLE IMAGEAPI SymFindExecutableImage(
  [in]  HANDLE                  hProcess,
  [in]  PCSTR                   FileName,
  [out] PSTR                    ImageFilePath,
  [in]  PFIND_EXE_FILE_CALLBACK Callback,
  [in]  PVOID                   CallerData
);