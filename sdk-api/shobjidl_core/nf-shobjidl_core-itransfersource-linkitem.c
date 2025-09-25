HRESULT LinkItem(
  [in]  IShellItem            *psiSource,
  [in]  IShellItem            *psiParentDest,
  [in]  LPCWSTR               pszNewName,
  [in]  TRANSFER_SOURCE_FLAGS flags,
  [out] IShellItem            **ppsiNewDest
);