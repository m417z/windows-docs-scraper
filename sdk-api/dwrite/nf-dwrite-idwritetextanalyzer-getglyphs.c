HRESULT GetGlyphs(
  [in]           WCHAR const                       *textString,
                 UINT32                            textLength,
                 IDWriteFontFace                   *fontFace,
                 BOOL                              isSideways,
                 BOOL                              isRightToLeft,
  [in]           DWRITE_SCRIPT_ANALYSIS const      *scriptAnalysis,
  [in, optional] WCHAR const                       *localeName,
  [optional]     IDWriteNumberSubstitution         *numberSubstitution,
  [in, optional] DWRITE_TYPOGRAPHIC_FEATURES const **features,
  [in, optional] UINT32 const                      *featureRangeLengths,
                 UINT32                            featureRanges,
                 UINT32                            maxGlyphCount,
  [out]          UINT16                            *clusterMap,
  [out]          DWRITE_SHAPING_TEXT_PROPERTIES    *textProps,
  [out]          UINT16                            *glyphIndices,
  [out]          DWRITE_SHAPING_GLYPH_PROPERTIES   *glyphProps,
  [out]          UINT32                            *actualGlyphCount
);