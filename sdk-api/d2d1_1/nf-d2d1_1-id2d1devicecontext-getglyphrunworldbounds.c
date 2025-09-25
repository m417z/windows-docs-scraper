HRESULT GetGlyphRunWorldBounds(
        D2D1_POINT_2F          baselineOrigin,
  [in]  const DWRITE_GLYPH_RUN *glyphRun,
        DWRITE_MEASURING_MODE  measuringMode,
  [out] D2D1_RECT_F            *bounds
);