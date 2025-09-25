HRESULT SHResolveFolderPathInLibrary(
  [in]  IShellLibrary *plib,
  [in]  PCWSTR        pszFolderPath,
  [in]  DWORD         dwTimeout,
  [out] PWSTR         *ppszResolvedPath
);