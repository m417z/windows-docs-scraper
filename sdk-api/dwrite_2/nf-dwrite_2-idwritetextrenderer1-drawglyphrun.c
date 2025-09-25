HRESULT DrawGlyphRun(
       void                               *clientDrawingContext,
       FLOAT                              baselineOriginX,
       FLOAT                              baselineOriginY,
       DWRITE_GLYPH_ORIENTATION_ANGLE     orientationAngle,
       DWRITE_MEASURING_MODE              measuringMode,
  [in] DWRITE_GLYPH_RUN const             *glyphRun,
  [in] DWRITE_GLYPH_RUN_DESCRIPTION const *glyphRunDescription,
       IUnknown                           *clientDrawingEffect
);