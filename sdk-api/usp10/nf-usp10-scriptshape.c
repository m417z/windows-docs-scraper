HRESULT ScriptShape(
  [in]      HDC             hdc,
  [in, out] SCRIPT_CACHE    *psc,
  [in]      const WCHAR     *pwcChars,
  [in]      int             cChars,
  [in]      int             cMaxGlyphs,
  [in, out] SCRIPT_ANALYSIS *psa,
  [out]     WORD            *pwOutGlyphs,
  [out]     WORD            *pwLogClust,
  [out]     SCRIPT_VISATTR  *psva,
  [out]     int             *pcGlyphs
);