HRESULT ExecNotificationQuery(
  [in]  const BSTR           strQueryLanguage,
  [in]  const BSTR           strQuery,
  [in]  long                 lFlags,
  [in]  IWbemContext         *pCtx,
  [out] IEnumWbemClassObject **ppEnum
);