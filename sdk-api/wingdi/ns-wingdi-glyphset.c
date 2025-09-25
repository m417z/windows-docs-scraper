typedef struct tagGLYPHSET {
  DWORD   cbThis;
  DWORD   flAccel;
  DWORD   cGlyphsSupported;
  DWORD   cRanges;
  WCRANGE ranges[1];
} GLYPHSET, *PGLYPHSET, *LPGLYPHSET;