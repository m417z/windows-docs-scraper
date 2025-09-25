SHSTDAPI SHCreateItemWithParent(
  [in]  PCIDLIST_ABSOLUTE pidlParent,
  [in]  IShellFolder      *psfParent,
  [in]  PCUITEMID_CHILD   pidl,
  [in]  REFIID            riid,
  [out] void              **ppvItem
);