SHSTDAPI SHCreateShellItem(
  [in, optional] PCIDLIST_ABSOLUTE pidlParent,
  [in, optional] IShellFolder      *psfParent,
  [in]           PCUITEMID_CHILD   pidl,
  [out]          IShellItem        **ppsi
);