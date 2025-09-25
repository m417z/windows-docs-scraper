HRESULT CheckTypographicFeature(
                 IDWriteFontFace         *fontFace,
                 DWRITE_SCRIPT_ANALYSIS  scriptAnalysis,
  [in, optional] WCHAR const             *localeName,
                 DWRITE_FONT_FEATURE_TAG featureTag,
                 UINT32                  glyphCount,
  [in]           UINT16 const            *glyphIndices,
  [out]          UINT8                   *featureApplies
);