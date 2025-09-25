HRESULT DrawInlineObject(
  void                           *clientDrawingContext,
  FLOAT                          originX,
  FLOAT                          originY,
  DWRITE_GLYPH_ORIENTATION_ANGLE orientationAngle,
  IDWriteInlineObject            *inlineObject,
  BOOL                           isSideways,
  BOOL                           isRightToLeft,
  IUnknown                       *clientDrawingEffect
);