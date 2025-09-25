HRESULT BuildArmingPatternData(
  [in]  IStream                     *UserModelData,
  [in]  KEYWORDSELECTOR             *KeywordSelectors,
  [in]  ULONG                       NumKeywordSelectors,
  [out] SOUNDDETECTOR_PATTERNHEADER **ppPatternData
);