HRESULT GetGlyphImageData(
  [in]  UINT16                     glyphId,
        UINT32                     pixelsPerEm,
        DWRITE_GLYPH_IMAGE_FORMATS glyphImageFormat,
  [out] DWRITE_GLYPH_IMAGE_DATA    *glyphData,
  [out] void                       **glyphDataContext
);