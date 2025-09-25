HRESULT GetGdiCompatibleGlyphMetrics(
                 FLOAT                emSize,
                 FLOAT                pixelsPerDip,
  [in, optional] DWRITE_MATRIX const  *transform,
                 BOOL                 useGdiNatural,
  [in]           UINT16 const         *glyphIndices,
                 UINT32               glyphCount,
  [out]          DWRITE_GLYPH_METRICS *glyphMetrics,
                 BOOL                 isSideways
);