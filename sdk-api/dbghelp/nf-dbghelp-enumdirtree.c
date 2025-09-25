BOOL IMAGEAPI EnumDirTree(
  [in, optional]  HANDLE                hProcess,
  [in]            PCSTR                 RootPath,
  [in]            PCSTR                 InputPathName,
  [out, optional] PSTR                  OutputPathBuffer,
  [in, optional]  PENUMDIRTREE_CALLBACK cb,
  [in, optional]  PVOID                 data
);