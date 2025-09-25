HRESULT ConnectServer(
  [in]  const BSTR    strNetworkResource,
  [in]  const BSTR    strUser,
  [in]  const BSTR    strPassword,
  [in]  const BSTR    strLocale,
  [in]  long          lSecurityFlags,
  [in]  const BSTR    strAuthority,
  [in]  IWbemContext  *pCtx,
  [out] IWbemServices **ppNamespace
);