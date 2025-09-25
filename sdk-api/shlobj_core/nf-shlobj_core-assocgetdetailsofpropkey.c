SHSTDAPI AssocGetDetailsOfPropKey(
  [in]  IShellFolder      *psf,
  [in]  PCUITEMID_CHILD   pidl,
  [in]  const PROPERTYKEY *pkey,
  [out] VARIANT           *pv,
  [out] BOOL              *pfFoundPropKey
);