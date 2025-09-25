HRESULT CreateGlyphRunAnalysis(
  [in]           DWRITE_GLYPH_RUN const  *glyphRun,
                 FLOAT                   pixelsPerDip,
  [in, optional] DWRITE_MATRIX const     *transform,
                 DWRITE_RENDERING_MODE   renderingMode,
                 DWRITE_MEASURING_MODE   measuringMode,
                 FLOAT                   baselineOriginX,
                 FLOAT                   baselineOriginY,
  [out]          IDWriteGlyphRunAnalysis **glyphRunAnalysis
);