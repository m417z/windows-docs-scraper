void DrawGlyphRunWithColorSupport(
  D2D1_POINT_2F                       baselineOrigin,
  const DWRITE_GLYPH_RUN              *glyphRun,
  const DWRITE_GLYPH_RUN_DESCRIPTION  *glyphRunDescription,
  ID2D1Brush                          *foregroundBrush,
  ID2D1SvgGlyphStyle                  *svgGlyphStyle,
  UINT32                              colorPaletteIndex,
  DWRITE_MEASURING_MODE               measuringMode,
  D2D1_COLOR_BITMAP_GLYPH_SNAP_OPTION bitmapSnapOption
);