HRESULT ScriptGetCMap(
  [in]      HDC          hdc,
  [in, out] SCRIPT_CACHE *psc,
  [in]      const WCHAR  *pwcInChars,
  [in]      int          cChars,
  [in]      DWORD        dwFlags,
  [out]     WORD         *pwOutGlyphs
);