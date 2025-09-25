SHSTDAPI SHCreateDataObject(
  [in, optional] PCIDLIST_ABSOLUTE     pidlFolder,
  [in]           UINT                  cidl,
  [in, optional] PCUITEMID_CHILD_ARRAY apidl,
  [in, optional] IDataObject           *pdtInner,
  [in]           REFIID                riid,
  [out]          void                  **ppv
);