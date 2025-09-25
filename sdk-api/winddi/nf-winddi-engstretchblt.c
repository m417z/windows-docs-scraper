ENGAPI BOOL EngStretchBlt(
       SURFOBJ         *psoDest,
       SURFOBJ         *psoSrc,
       SURFOBJ         *psoMask,
       CLIPOBJ         *pco,
       XLATEOBJ        *pxlo,
  [in] COLORADJUSTMENT *pca,
  [in] POINTL          *pptlHTOrg,
  [in] RECTL           *prclDest,
  [in] RECTL           *prclSrc,
       POINTL          *pptlMask,
  [in] ULONG           iMode
);