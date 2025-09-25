HRESULT ScriptGetFontLanguageTags(
  [in, optional] HDC             hdc,
  [in, out]      SCRIPT_CACHE    *psc,
  [in, optional] SCRIPT_ANALYSIS *psa,
  [in]           OPENTYPE_TAG    tagScript,
  [in]           int             cMaxTags,
  [out]          OPENTYPE_TAG    *pLangsysTags,
  [out]          int             *pcTags
);