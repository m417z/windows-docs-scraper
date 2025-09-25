LONG DrvQueryTrueTypeOutline(
  DHPDEV          dhpdev,
  FONTOBJ         *pfo,
  HGLYPH          hglyph,
  BOOL            bMetricsOnly,
  GLYPHDATA       *pgldt,
  ULONG           cjBuf,
  TTPOLYGONHEADER *ppoly
);