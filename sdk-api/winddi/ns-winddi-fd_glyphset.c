typedef struct _FD_GLYPHSET {
  ULONG cjThis;
  FLONG flAccel;
  ULONG cGlyphsSupported;
  ULONG cRuns;
  WCRUN awcrun[1];
} FD_GLYPHSET, *PFD_GLYPHSET;