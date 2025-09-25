HRESULT GetObject(
  [in]  const BSTR       strObjectPath,
  [in]  long             lFlags,
  [in]  IWbemContext     *pCtx,
  [out] IWbemClassObject **ppObject,
  [out] IWbemCallResult  **ppCallResult
);