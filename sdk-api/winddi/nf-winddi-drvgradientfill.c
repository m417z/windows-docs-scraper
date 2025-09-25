BOOL DrvGradientFill(
  [in, out]      SURFOBJ   *psoDest,
  [in]           CLIPOBJ   *pco,
  [in, optional] XLATEOBJ  *pxlo,
  [in]           TRIVERTEX *pVertex,
  [in]           ULONG     nVertex,
  [in]           PVOID     pMesh,
  [in]           ULONG     nMesh,
  [in]           RECTL     *prclExtents,
  [in]           POINTL    *pptlDitherOrg,
  [in]           ULONG     ulMode
);