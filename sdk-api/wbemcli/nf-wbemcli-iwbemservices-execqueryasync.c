HRESULT ExecQueryAsync(
  [in] const BSTR      strQueryLanguage,
  [in] const BSTR      strQuery,
  [in] long            lFlags,
  [in] IWbemContext    *pCtx,
  [in] IWbemObjectSink *pResponseHandler
);