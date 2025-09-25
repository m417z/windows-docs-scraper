HRESULT ScriptGetFontFeatureTags(
  [in, optional] HDC             hdc,
  [in, out]      SCRIPT_CACHE    *psc,
  [in, optional] SCRIPT_ANALYSIS *psa,
  [in]           OPENTYPE_TAG    tagScript,
  [in]           OPENTYPE_TAG    tagLangSys,
  [in]           int             cMaxTags,
  [out]          OPENTYPE_TAG    *pFeatureTags,
  [out]          int             *pcTags
);