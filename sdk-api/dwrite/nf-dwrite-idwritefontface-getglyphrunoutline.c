HRESULT GetGlyphRunOutline(
                 FLOAT                     emSize,
  [in]           UINT16 const              *glyphIndices,
  [in, optional] FLOAT const               *glyphAdvances,
  [in, optional] DWRITE_GLYPH_OFFSET const *glyphOffsets,
                 UINT32                    glyphCount,
                 BOOL                      isSideways,
                 BOOL                      isRightToLeft,
                 IDWriteGeometrySink       *geometrySink
);