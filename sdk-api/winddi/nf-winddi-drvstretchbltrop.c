BOOL DrvStretchBltROP(
  [in, out]      SURFOBJ         *psoDest,
  [in, out]      SURFOBJ         *psoSrc,
  [in, optional] SURFOBJ         *psoMask,
  [in]           CLIPOBJ         *pco,
  [in, optional] XLATEOBJ        *pxlo,
  [in, optional] COLORADJUSTMENT *pca,
  [in]           POINTL          *pptlHTOrg,
  [in]           RECTL           *prclDest,
  [in]           RECTL           *prclSrc,
  [in, optional] POINTL          *pptlMask,
  [in]           ULONG           iMode,
  [in]           BRUSHOBJ        *pbo,
  [in]           DWORD           rop4
);