HRESULT GetColorBitmapGlyphImage(
                 DWRITE_GLYPH_IMAGE_FORMATS glyphImageFormat,
                 D2D1_POINT_2F              glyphOrigin,
  [in]           IDWriteFontFace            *fontFace,
                 FLOAT                      fontEmSize,
                 UINT16                     glyphIndex,
                 BOOL                       isSideways,
  [in, optional] const D2D1_MATRIX_3X2_F    *worldTransform,
                 FLOAT                      dpiX,
                 FLOAT                      dpiY,
  [out]          D2D1_MATRIX_3X2_F          *glyphTransform,
  [out]          ID2D1Image                 **glyphImage
);