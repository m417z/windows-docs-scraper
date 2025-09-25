HRESULT GetJustificationOpportunities(
        IDWriteFontFace                       *fontFace,
        FLOAT                                 fontEmSize,
        DWRITE_SCRIPT_ANALYSIS                scriptAnalysis,
        UINT32                                textLength,
        UINT32                                glyphCount,
  [in]  WCHAR const                           *textString,
  [in]  UINT16 const                          *clusterMap,
  [in]  DWRITE_SHAPING_GLYPH_PROPERTIES const *glyphProperties,
  [out] DWRITE_JUSTIFICATION_OPPORTUNITY      *justificationOpportunities
);