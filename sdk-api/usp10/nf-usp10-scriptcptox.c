HRESULT ScriptCPtoX(
  [in]  int                   iCP,
  [in]  BOOL                  fTrailing,
  [in]  int                   cChars,
  [in]  int                   cGlyphs,
  [in]  const WORD            *pwLogClust,
  [in]  const SCRIPT_VISATTR  *psva,
  [in]  const int             *piAdvance,
  [in]  const SCRIPT_ANALYSIS *psa,
  [out] int                   *piX
);