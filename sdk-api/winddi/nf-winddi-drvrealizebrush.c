BOOL DrvRealizeBrush(
  [in]           BRUSHOBJ *pbo,
  [in, out]      SURFOBJ  *psoTarget,
  [in]           SURFOBJ  *psoPattern,
  [in, optional] SURFOBJ  *psoMask,
  [in]           XLATEOBJ *pxlo,
  [in]           ULONG    iHatch
);