HRESULT ProcessFullEnumerationChangeBatch(
  [in]      CONFLICT_RESOLUTION_POLICY      resolutionPolicy,
  [in]      ISyncFullEnumerationChangeBatch *pSourceChangeBatch,
  [in]      IUnknown                        *pUnkDataRetriever,
  [in]      ISyncCallback                   *pCallback,
  [in, out] SYNC_SESSION_STATISTICS         *pSyncSessionStatistics
);