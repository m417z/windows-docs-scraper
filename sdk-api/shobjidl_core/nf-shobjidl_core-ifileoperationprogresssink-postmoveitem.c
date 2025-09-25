HRESULT PostMoveItem(
  [in] DWORD      dwFlags,
  [in] IShellItem *psiItem,
  [in] IShellItem *psiDestinationFolder,
  [in] LPCWSTR    pszNewName,
  [in] HRESULT    hrMove,
  [in] IShellItem *psiNewlyCreated
);