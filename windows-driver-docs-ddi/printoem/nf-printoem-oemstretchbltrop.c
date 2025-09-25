BOOL OEMStretchBltROP(
  SURFOBJ         *psoDest,
  SURFOBJ         *psoSrc,
  SURFOBJ         *psoMask,
  CLIPOBJ         *pco,
  XLATEOBJ        *pxlo,
  COLORADJUSTMENT *pca,
  POINTL          *pptlHTOrg,
  RECTL           *prclDest,
  RECTL           *prclSrc,
  POINTL          *pptlMask,
  ULONG           iMode,
  BRUSHOBJ        *pbo,
  ROP4            rop4
);