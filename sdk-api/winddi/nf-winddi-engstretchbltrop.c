ENGAPI BOOL EngStretchBltROP(
       SURFOBJ         *psoDest,
       SURFOBJ         *psoSrc,
       SURFOBJ         *psoMask,
       CLIPOBJ         *pco,
       XLATEOBJ        *pxlo,
       COLORADJUSTMENT *pca,
       POINTL          *pptlHTOrg,
  [in] RECTL           *prclDest,
  [in] RECTL           *prclSrc,
       POINTL          *pptlMask,
  [in] ULONG           iMode,
       BRUSHOBJ        *pbo,
  [in] DWORD           rop4
);