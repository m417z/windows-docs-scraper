HRESULT RecycleItem(
  [in]  IShellItem            *psiSource,
  [in]  IShellItem            *psiParentDest,
  [in]  TRANSFER_SOURCE_FLAGS flags,
  [out] IShellItem            **ppsiNewDest
);