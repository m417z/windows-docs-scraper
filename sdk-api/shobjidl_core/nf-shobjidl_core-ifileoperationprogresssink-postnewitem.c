HRESULT PostNewItem(
  [in] DWORD      dwFlags,
  [in] IShellItem *psiDestinationFolder,
  [in] LPCWSTR    pszNewName,
  [in] LPCWSTR    pszTemplateName,
  [in] DWORD      dwFileAttributes,
  [in] HRESULT    hrNew,
  [in] IShellItem *psiNewItem
);