BOOL DrvStrokeAndFillPath(
  [in, out]      SURFOBJ   *pso,
  [in, out]      PATHOBJ   *ppo,
  [in]           CLIPOBJ   *pco,
  [in, optional] XFORMOBJ  *pxo,
  [in]           BRUSHOBJ  *pboStroke,
  [in]           LINEATTRS *plineattrs,
  [in]           BRUSHOBJ  *pboFill,
  [in]           POINTL    *pptlBrushOrg,
  [in]           MIX       mixFill,
  [in]           FLONG     flOptions
);