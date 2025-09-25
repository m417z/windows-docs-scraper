BOOL DrvTransparentBlt(
  [in, out]      SURFOBJ  *psoDst,
  [in]           SURFOBJ  *psoSrc,
  [in]           CLIPOBJ  *pco,
  [in, optional] XLATEOBJ *pxlo,
  [in]           RECTL    *prclDst,
  [in]           RECTL    *prclSrc,
  [in]           ULONG    iTransColor,
  [in]           ULONG    ulReserved
);