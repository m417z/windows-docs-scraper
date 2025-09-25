HRESULT GetGdiCompatibleGlyphAdvances(
                 FLOAT               emSize,
                 FLOAT               pixelsPerDip,
  [in, optional] DWRITE_MATRIX const *transform,
                 BOOL                useGdiNatural,
                 BOOL                isSideways,
                 UINT32              glyphCount,
  [in]           UINT16 const        *glyphIndices,
  [out]          INT32               *glyphAdvances
);