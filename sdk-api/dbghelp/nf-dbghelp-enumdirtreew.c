BOOL IMAGEAPI EnumDirTreeW(
  [in, optional]  HANDLE                 hProcess,
  [in]            PCWSTR                 RootPath,
  [in]            PCWSTR                 InputPathName,
  [out, optional] PWSTR                  OutputPathBuffer,
  [in, optional]  PENUMDIRTREE_CALLBACKW cb,
  [in, optional]  PVOID                  data
);