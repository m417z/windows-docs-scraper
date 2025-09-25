BOOL DrvBitBlt(
  [in, out]      SURFOBJ  *psoTrg,
  [in, optional] SURFOBJ  *psoSrc,
  [in, optional] SURFOBJ  *psoMask,
  [in]           CLIPOBJ  *pco,
  [in, optional] XLATEOBJ *pxlo,
  [in]           RECTL    *prclTrg,
  [in, optional] POINTL   *pptlSrc,
  [in, optional] POINTL   *pptlMask,
  [in, optional] BRUSHOBJ *pbo,
  [in, optional] POINTL   *pptlBrush,
  [in]           ROP4     rop4
);