HRESULT SHSaveLibraryInFolderPath(
  [in]            IShellLibrary    *plib,
  [in]            PCWSTR           pszFolderPath,
  [in]            PCWSTR           pszLibraryName,
  [in]            LIBRARYSAVEFLAGS lsf,
  [out, optional] PWSTR            *ppszSavedToPath
);