HRESULT OpenNamespace(
  [in]  const BSTR      strNamespace,
  [in]  long            lFlags,
  [in]  IWbemContext    *pCtx,
  [out] IWbemServices   **ppWorkingNamespace,
  [out] IWbemCallResult **ppResult
);