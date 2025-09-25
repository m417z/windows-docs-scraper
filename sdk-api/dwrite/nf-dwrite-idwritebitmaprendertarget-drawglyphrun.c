HRESULT DrawGlyphRun(
                  FLOAT                  baselineOriginX,
                  FLOAT                  baselineOriginY,
                  DWRITE_MEASURING_MODE  measuringMode,
  [in]            DWRITE_GLYPH_RUN const *glyphRun,
                  IDWriteRenderingParams *renderingParams,
                  COLORREF               textColor,
  [out, optional] RECT                   *blackBoxRect
);