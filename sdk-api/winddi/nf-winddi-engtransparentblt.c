ENGAPI BOOL EngTransparentBlt(
  [in]           SURFOBJ  *psoDst,
  [in]           SURFOBJ  *psoSrc,
  [in, optional] CLIPOBJ  *pco,
  [in, optional] XLATEOBJ *pxlo,
  [in]           RECTL    *prclDst,
  [in]           RECTL    *prclSrc,
  [in]           ULONG    TransColor,
  [in]           ULONG    bCalledFromBitBlt
);