HRESULT GetDesignGlyphMetrics(
  [in]  UINT16 const         *glyphIndices,
        UINT32               glyphCount,
  [out] DWRITE_GLYPH_METRICS *glyphMetrics,
        BOOL                 isSideways
);