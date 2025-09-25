HRESULT CreateRefreshableObject(
  [in]  IWbemServices     *pNamespace,
  [in]  IWbemObjectAccess *pTemplate,
  [in]  IWbemRefresher    *pRefresher,
  [in]  long              lFlags,
  [in]  IWbemContext      *pContext,
  [out] IWbemObjectAccess **ppRefreshable,
  [out] long              *plId
);