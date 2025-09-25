HRESULT ScriptShapeOpenType(
  [in, optional] HDC                  hdc,
  [in, out]      SCRIPT_CACHE         *psc,
  [in, out]      SCRIPT_ANALYSIS      *psa,
  [in]           OPENTYPE_TAG         tagScript,
  [in]           OPENTYPE_TAG         tagLangSys,
  [in, optional] int                  *rcRangeChars,
  [in, optional] TEXTRANGE_PROPERTIES **rpRangeProperties,
  [in]           int                  cRanges,
  [in]           const WCHAR          *pwcChars,
  [in]           int                  cChars,
  [in]           int                  cMaxGlyphs,
  [out]          WORD                 *pwLogClust,
  [out]          SCRIPT_CHARPROP      *pCharProps,
  [out]          WORD                 *pwOutGlyphs,
  [out]          SCRIPT_GLYPHPROP     *pOutGlyphProps,
  [out]          int                  *pcGlyphs
);