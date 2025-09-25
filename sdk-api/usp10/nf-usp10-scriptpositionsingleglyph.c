HRESULT ScriptPositionSingleGlyph(
  [in, optional] HDC             hdc,
  [in, out]      SCRIPT_CACHE    *psc,
  [in, optional] SCRIPT_ANALYSIS *psa,
  [in]           OPENTYPE_TAG    tagScript,
  [in]           OPENTYPE_TAG    tagLangSys,
  [in]           OPENTYPE_TAG    tagFeature,
  [in]           LONG            lParameter,
  [in]           WORD            wGlyphId,
  [in]           int             iAdvance,
  [in]           GOFFSET         GOffset,
  [out]          int             *piOutAdvance,
  [out]          GOFFSET         *pOutGoffset
);