struct DWRITE_GLYPH_RUN {
  IDWriteFontFace           *fontFace;
  FLOAT                     fontEmSize;
  UINT32                    glyphCount;
  UINT16 const              *glyphIndices;
  FLOAT const               *glyphAdvances;
  DWRITE_GLYPH_OFFSET const *glyphOffsets;
  BOOL                      isSideways;
  UINT32                    bidiLevel;
};