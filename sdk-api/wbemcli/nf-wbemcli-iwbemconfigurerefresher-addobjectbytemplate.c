HRESULT AddObjectByTemplate(
        IWbemServices    *pNamespace,
  [in]  IWbemClassObject *pTemplate,
  [in]  long             lFlags,
  [in]  IWbemContext     *pContext,
  [out] IWbemClassObject **ppRefreshable,
  [out] long             *plId
);