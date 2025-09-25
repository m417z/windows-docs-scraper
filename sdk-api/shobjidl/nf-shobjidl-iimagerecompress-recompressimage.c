HRESULT RecompressImage(
  [in]      IShellItem *psi,
  [in]      int        cx,
  [in]      int        cy,
  [in]      int        iQuality,
  [in]      IStorage   *pstg,
  [in, out] IStream    **ppstrmOut
);