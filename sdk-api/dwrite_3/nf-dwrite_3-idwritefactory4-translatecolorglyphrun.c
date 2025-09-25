HRESULT TranslateColorGlyphRun(
                 D2D1_POINT_2F                      baselineOrigin,
  [in]           DWRITE_GLYPH_RUN const             *glyphRun,
  [in, optional] DWRITE_GLYPH_RUN_DESCRIPTION const *glyphRunDescription,
                 DWRITE_GLYPH_IMAGE_FORMATS         desiredGlyphImageFormats,
                 DWRITE_MEASURING_MODE              measuringMode,
  [in, optional] DWRITE_MATRIX const                *worldAndDpiTransform,
                 UINT32                             colorPaletteIndex,
  [out]          IDWriteColorGlyphRunEnumerator1    **colorLayers
);