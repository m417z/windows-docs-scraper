HRESULT ComputeGlyphOrigins(
  DWRITE_GLYPH_RUN const *glyphRun,
  DWRITE_MEASURING_MODE  measuringMode,
  D2D1_POINT_2F          baselineOrigin,
  DWRITE_MATRIX const    *worldAndDpiTransform,
  D2D1_POINT_2F          *glyphOrigins
);