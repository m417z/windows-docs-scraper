HRESULT CreateGlyphRunAnalysis(
  [in]           DWRITE_GLYPH_RUN const     *glyphRun,
  [in, optional] DWRITE_MATRIX const        *transform,
                 DWRITE_RENDERING_MODE      renderingMode,
                 DWRITE_MEASURING_MODE      measuringMode,
                 DWRITE_GRID_FIT_MODE       gridFitMode,
                 DWRITE_TEXT_ANTIALIAS_MODE antialiasMode,
                 FLOAT                      baselineOriginX,
                 FLOAT                      baselineOriginY,
  [out]          IDWriteGlyphRunAnalysis    **glyphRunAnalysis
);