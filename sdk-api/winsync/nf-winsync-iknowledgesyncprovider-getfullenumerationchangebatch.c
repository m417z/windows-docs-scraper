HRESULT GetFullEnumerationChangeBatch(
  [in]  DWORD                           dwBatchSize,
  [in]  const BYTE                      *pbLowerEnumerationBound,
  [in]  ISyncKnowledge                  *pSyncKnowledge,
  [out] ISyncFullEnumerationChangeBatch **ppSyncChangeBatch,
  [out] IUnknown                        **ppUnkDataRetriever
);