SHSTDAPI SHBindToFolderIDListParentEx(
  [in, optional]  IShellFolder       *psfRoot,
  [in]            PCUIDLIST_RELATIVE pidl,
  [in, optional]  IBindCtx           *ppbc,
  [in]            REFIID             riid,
  [out]           void               **ppv,
  [out, optional] PCUITEMID_CHILD    *ppidlLast
);