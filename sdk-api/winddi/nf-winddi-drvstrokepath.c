BOOL DrvStrokePath(
  [in, out]      SURFOBJ   *pso,
  [in]           PATHOBJ   *ppo,
  [in]           CLIPOBJ   *pco,
  [in, optional] XFORMOBJ  *pxo,
  [in]           BRUSHOBJ  *pbo,
  [in]           POINTL    *pptlBrushOrg,
  [in]           LINEATTRS *plineattrs,
  [in]           MIX       mix
);