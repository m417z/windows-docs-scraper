struct DWRITE_COLOR_GLYPH_RUN {
  DWRITE_GLYPH_RUN             glyphRun;
  DWRITE_GLYPH_RUN_DESCRIPTION *glyphRunDescription;
  FLOAT                        baselineOriginX;
  FLOAT                        baselineOriginY;
  DWRITE_COLOR_F               runColor;
  UINT16                       paletteIndex;
};