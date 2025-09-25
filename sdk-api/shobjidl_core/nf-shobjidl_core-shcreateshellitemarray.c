SHSTDAPI SHCreateShellItemArray(
  [in]  PCIDLIST_ABSOLUTE     pidlParent,
  [in]  IShellFolder          *psf,
  [in]  UINT                  cidl,
  [in]  PCUITEMID_CHILD_ARRAY ppidl,
  [out] IShellItemArray       **ppsiItemArray
);