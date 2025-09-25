void DrawSvgGlyphRun(
                 D2D1_POINT_2F          baselineOrigin,
  [in]           const DWRITE_GLYPH_RUN *glyphRun,
  [in, optional] ID2D1Brush             *defaultFillBrush,
  [in, optional] ID2D1SvgGlyphStyle     *svgGlyphStyle,
                 UINT32                 colorPaletteIndex,
                 DWRITE_MEASURING_MODE  measuringMode
);