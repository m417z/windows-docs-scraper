HRESULT ScriptTextOut(
  [in]           const HDC             hdc,
  [in, out]      SCRIPT_CACHE          *psc,
  [in]           int                   x,
  [in]           int                   y,
  [in]           UINT                  fuOptions,
  [in, optional] const RECT            *lprc,
  [in]           const SCRIPT_ANALYSIS *psa,
  [in]           const WCHAR           *pwcReserved,
  [in]           int                   iReserved,
  [in]           const WORD            *pwGlyphs,
  [in]           int                   cGlyphs,
  [in]           const int             *piAdvance,
  [in, optional] const int             *piJustify,
  [in]           const GOFFSET         *pGoffset
);