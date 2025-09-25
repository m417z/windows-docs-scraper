HRESULT ScriptGetFontAlternateGlyphs(
  [in, optional] HDC             hdc,
  [in, out]      SCRIPT_CACHE    *psc,
  [in, optional] SCRIPT_ANALYSIS *psa,
  [in]           OPENTYPE_TAG    tagScript,
  [in]           OPENTYPE_TAG    tagLangSys,
  [in]           OPENTYPE_TAG    tagFeature,
  [in]           WORD            wGlyphId,
  [in]           int             cMaxAlternates,
  [out]          WORD            *pAlternateGlyphs,
  [out]          int             *pcAlternates
);