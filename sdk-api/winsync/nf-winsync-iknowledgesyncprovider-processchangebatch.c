HRESULT ProcessChangeBatch(
  [in]      CONFLICT_RESOLUTION_POLICY resolutionPolicy,
  [in]      ISyncChangeBatch           *pSourceChangeBatch,
  [in]      IUnknown                   *pUnkDataRetriever,
  [in]      ISyncCallback              *pCallback,
  [in, out] SYNC_SESSION_STATISTICS    *pSyncSessionStatistics
);