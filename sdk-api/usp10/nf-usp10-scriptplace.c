HRESULT ScriptPlace(
  [in]      HDC                  hdc,
  [in, out] SCRIPT_CACHE         *psc,
  [in]      const WORD           *pwGlyphs,
  [in]      int                  cGlyphs,
  [in]      const SCRIPT_VISATTR *psva,
  [in, out] SCRIPT_ANALYSIS      *psa,
  [out]     int                  *piAdvance,
  [out]     GOFFSET              *pGoffset,
  [out]     ABC                  *pABC
);