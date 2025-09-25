HRESULT ScriptXtoCP(
  [in]  int                   iX,
  [in]  int                   cChars,
  [in]  int                   cGlyphs,
  [in]  const WORD            *pwLogClust,
  [in]  const SCRIPT_VISATTR  *psva,
  [in]  const int             *piAdvance,
  [in]  const SCRIPT_ANALYSIS *psa,
  [out] int                   *piCP,
  [out] int                   *piTrailing
);