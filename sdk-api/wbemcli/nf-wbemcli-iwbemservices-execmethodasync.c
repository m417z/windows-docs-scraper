HRESULT ExecMethodAsync(
  [in] const BSTR       strObjectPath,
  [in] const BSTR       strMethodName,
  [in] long             lFlags,
  [in] IWbemContext     *pCtx,
  [in] IWbemClassObject *pInParams,
  [in] IWbemObjectSink  *pResponseHandler
);