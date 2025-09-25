HRESULT ParseDetectionResultData(
  [in]  IStream                     *UserModelData,
  [in]  SOUNDDETECTOR_PATTERNHEADER *Result,
  [out] KEYWORDID                   *KeywordId,
  [out] LANGID                      *LangId,
  [out] BOOL                        *pIsUserMatch,
  [out] ULONG64                     *KeywordStartPerformanceCounterValue,
  [out] ULONG64                     *KeywordEndPerformanceCounterValue
);