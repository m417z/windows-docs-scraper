HRESULT ParseDisplayName(
  [in]  IBindCtx *pbc,
  [in]  LPOLESTR pszDisplayName,
  [out] ULONG    *pchEaten,
  [out] IMoniker **ppmkOut
);