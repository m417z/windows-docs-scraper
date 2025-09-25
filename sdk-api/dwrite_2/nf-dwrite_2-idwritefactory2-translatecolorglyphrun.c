HRESULT TranslateColorGlyphRun(
                 FLOAT                              baselineOriginX,
                 FLOAT                              baselineOriginY,
  [in]           DWRITE_GLYPH_RUN const             *glyphRun,
  [in, optional] DWRITE_GLYPH_RUN_DESCRIPTION const *glyphRunDescription,
                 DWRITE_MEASURING_MODE              measuringMode,
  [in, optional] DWRITE_MATRIX const                *worldToDeviceTransform,
                 UINT32                             colorPaletteIndex,
  [out]          IDWriteColorGlyphRunEnumerator     **colorLayers
);