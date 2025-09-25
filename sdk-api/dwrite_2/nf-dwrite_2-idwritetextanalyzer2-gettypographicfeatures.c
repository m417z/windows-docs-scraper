HRESULT GetTypographicFeatures(
                 IDWriteFontFace         *fontFace,
                 DWRITE_SCRIPT_ANALYSIS  scriptAnalysis,
  [in, optional] WCHAR const             *localeName,
                 UINT32                  maxTagCount,
  [out]          UINT32                  *actualTagCount,
  [out]          DWRITE_FONT_FEATURE_TAG *tags
);