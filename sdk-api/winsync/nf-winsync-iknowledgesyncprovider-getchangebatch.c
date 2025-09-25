HRESULT GetChangeBatch(
  [in]  DWORD            dwBatchSize,
  [in]  ISyncKnowledge   *pSyncKnowledge,
  [out] ISyncChangeBatch **ppSyncChangeBatch,
  [out] IUnknown         **ppUnkDataRetriever
);