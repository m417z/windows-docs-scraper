HRESULT GetJustifiedGlyphs(
                  IDWriteFontFace                       *fontFace,
                  FLOAT                                 fontEmSize,
                  DWRITE_SCRIPT_ANALYSIS                scriptAnalysis,
                  UINT32                                textLength,
                  UINT32                                glyphCount,
                  UINT32                                maxGlyphCount,
  [in, optional]  UINT16 const                          *clusterMap,
  [in]            UINT16 const                          *glyphIndices,
  [in]            FLOAT const                           *glyphAdvances,
  [in]            FLOAT const                           *justifiedGlyphAdvances,
  [in]            DWRITE_GLYPH_OFFSET const             *justifiedGlyphOffsets,
  [in]            DWRITE_SHAPING_GLYPH_PROPERTIES const *glyphProperties,
  [out]           UINT32                                *actualGlyphCount,
  [out, optional] UINT16                                *modifiedClusterMap,
  [out]           UINT16                                *modifiedGlyphIndices,
  [out]           FLOAT                                 *modifiedGlyphAdvances,
  [out]           DWRITE_GLYPH_OFFSET                   *modifiedGlyphOffsets
);