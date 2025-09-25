HRESULT GetRestrictedSink(
  [in]  long           lNumQueries,
  [in]  const LPCWSTR  *awszQueries,
  [in]  IUnknown       *pCallback,
  [out] IWbemEventSink **ppSink
);