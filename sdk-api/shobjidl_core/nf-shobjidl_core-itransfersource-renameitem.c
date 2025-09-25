HRESULT RenameItem(
  [in]  IShellItem            *psiSource,
  [in]  LPCWSTR               pszNewName,
  [in]  TRANSFER_SOURCE_FLAGS flags,
  [out] IShellItem            **ppsiNewDest
);