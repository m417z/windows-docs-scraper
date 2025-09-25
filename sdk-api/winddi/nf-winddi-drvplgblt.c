BOOL DrvPlgBlt(
  [in, out]      SURFOBJ         *psoTrg,
  [in, out]      SURFOBJ         *psoSrc,
  [in, optional] SURFOBJ         *psoMsk,
  [in]           CLIPOBJ         *pco,
  [in, optional] XLATEOBJ        *pxlo,
  [in, optional] COLORADJUSTMENT *pca,
  [in, optional] POINTL          *pptlBrushOrg,
  [in]           POINTFIX        *pptfx,
  [in]           RECTL           *prcl,
  [in, optional] POINTL          *pptl,
  [in]           ULONG           iMode
);