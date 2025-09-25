HRESULT ExecMethod(
  [in]  const BSTR       strObjectPath,
  [in]  const BSTR       strMethodName,
  [in]  long             lFlags,
  [in]  IWbemContext     *pCtx,
  [in]  IWbemClassObject *pInParams,
  [out] IWbemClassObject **ppOutParams,
  [out] IWbemCallResult  **ppCallResult
);