BOOL DrvAlphaBlend(
  [in, out]      SURFOBJ  *psoDest,
  [in]           SURFOBJ  *psoSrc,
  [in]           CLIPOBJ  *pco,
  [in, optional] XLATEOBJ *pxlo,
  [in]           RECTL    *prclDest,
  [in]           RECTL    *prclSrc,
  [in]           BLENDOBJ *pBlendObj
);