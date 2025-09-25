SHSTDAPI SHBindToFolderIDListParent(
  [in, optional]  IShellFolder       *psfRoot,
  [in]            PCUIDLIST_RELATIVE pidl,
  [in]            REFIID             riid,
  [out]           void               **ppv,
  [out, optional] PCUITEMID_CHILD    *ppidlLast
);