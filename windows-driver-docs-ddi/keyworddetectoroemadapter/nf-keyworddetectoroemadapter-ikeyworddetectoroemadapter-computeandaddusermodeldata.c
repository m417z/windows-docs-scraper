HRESULT ComputeAndAddUserModelData(
  [in] IStream         *ModelData,
  [in] KEYWORDSELECTOR KeywordSelector,
  [in] LONG            *KeywordEndBytePos,
  [in] IMFMediaBuffer  **UserRecordings,
  [in] ULONG           NumUserRecordings
);