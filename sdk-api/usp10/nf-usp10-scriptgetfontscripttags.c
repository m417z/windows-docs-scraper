HRESULT ScriptGetFontScriptTags(
  [in, optional] HDC             hdc,
  [in, out]      SCRIPT_CACHE    *psc,
  [in, optional] SCRIPT_ANALYSIS *psa,
  [in]           int             cMaxTags,
  [out]          OPENTYPE_TAG    *pScriptTags,
  [out]          int             *pcTags
);