HRESULT JustifyGlyphAdvances(
                  FLOAT                                  lineWidth,
                  UINT32                                 glyphCount,
  [in]            DWRITE_JUSTIFICATION_OPPORTUNITY const *justificationOpportunities,
  [in]            FLOAT const                            *glyphAdvances,
  [in]            DWRITE_GLYPH_OFFSET const              *glyphOffsets,
  [out]           FLOAT                                  *justifiedGlyphAdvances,
  [out, optional] DWRITE_GLYPH_OFFSET                    *justifiedGlyphOffsets
);