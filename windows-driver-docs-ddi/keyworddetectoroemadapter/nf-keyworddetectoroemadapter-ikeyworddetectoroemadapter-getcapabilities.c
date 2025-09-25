HRESULT GetCapabilities(
  [in]  BOOL         *SupportsUserModels,
  [out] KEYWORDID    **KeywordIds,
  [out] ULONG        *NumKeywords,
  [out] LANGID       **LangIds,
  [out] ULONG        *NumLanguages,
  [out] IMFMediaType **ppMediaType
);