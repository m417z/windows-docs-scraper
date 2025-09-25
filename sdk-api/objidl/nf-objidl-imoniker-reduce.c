HRESULT Reduce(
  [in]      IBindCtx *pbc,
  [in]      DWORD    dwReduceHowFar,
  [in, out] IMoniker **ppmkToLeft,
  [out]     IMoniker **ppmkReduced
);