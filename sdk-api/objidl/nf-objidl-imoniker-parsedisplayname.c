HRESULT ParseDisplayName(
  [in]  IBindCtx *pbc,
  [in]  IMoniker *pmkToLeft,
  [in]  LPOLESTR pszDisplayName,
  [out] ULONG    *pchEaten,
  [out] IMoniker **ppmkOut
);