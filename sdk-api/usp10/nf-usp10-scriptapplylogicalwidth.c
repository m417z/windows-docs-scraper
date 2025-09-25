HRESULT ScriptApplyLogicalWidth(
  [in]                const int             *piDx,
  [in]                int                   cChars,
  [in]                int                   cGlyphs,
  [in]                const WORD            *pwLogClust,
  [in]                const SCRIPT_VISATTR  *psva,
  [in]                const int             *piAdvance,
  [in]                const SCRIPT_ANALYSIS *psa,
  [in, out, optional] ABC                   *pABC,
  [out]               int                   *piJustify
);