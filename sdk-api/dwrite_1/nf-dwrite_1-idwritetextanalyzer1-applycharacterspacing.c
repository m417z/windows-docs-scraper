HRESULT ApplyCharacterSpacing(
        FLOAT                                 leadingSpacing,
        FLOAT                                 trailingSpacing,
        FLOAT                                 minimumAdvanceWidth,
        UINT32                                textLength,
        UINT32                                glyphCount,
  [in]  UINT16 const                          *clusterMap,
  [in]  FLOAT const                           *glyphAdvances,
  [in]  DWRITE_GLYPH_OFFSET const             *glyphOffsets,
  [in]  DWRITE_SHAPING_GLYPH_PROPERTIES const *glyphProperties,
  [out] FLOAT                                 *modifiedGlyphAdvances,
  [out] DWRITE_GLYPH_OFFSET                   *modifiedGlyphOffsets
);