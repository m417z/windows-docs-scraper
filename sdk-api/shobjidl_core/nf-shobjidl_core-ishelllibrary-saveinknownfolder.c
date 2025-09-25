HRESULT SaveInKnownFolder(
  [in]  REFKNOWNFOLDERID kfidToSaveIn,
  [in]  LPCWSTR          pszLibraryName,
  [in]  LIBRARYSAVEFLAGS lsf,
  [out] IShellItem       **ppsiSavedTo
);