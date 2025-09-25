HRESULT AddObjectByPath(
  [in]  IWbemServices    *pNamespace,
  [in]  LPCWSTR          wszPath,
  [in]  long             lFlags,
  [in]  IWbemContext     *pContext,
  [out] IWbemClassObject **ppRefreshable,
  [out] long             *plId
);