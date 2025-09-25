HRESULT DrawGlyphRun(
                 D2D1_POINT_2F                      baselineOrigin,
  [in]           const DWRITE_GLYPH_RUN             *glyphRun,
  [in, optional] const DWRITE_GLYPH_RUN_DESCRIPTION *glyphRunDescription,
  [in]           ID2D1Brush                         *foregroundBrush,
                 DWRITE_MEASURING_MODE              measuringMode
);