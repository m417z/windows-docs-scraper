HRESULT ScriptGetLogicalWidths(
  [in]  const SCRIPT_ANALYSIS *psa,
  [in]  int                   cChars,
  [in]  int                   cGlyphs,
  [in]  const int             *piGlyphWidth,
  [in]  const WORD            *pwLogClust,
  [in]  const SCRIPT_VISATTR  *psva,
  [out] int                   *piDx
);