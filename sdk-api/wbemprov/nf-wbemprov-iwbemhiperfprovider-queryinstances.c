HRESULT QueryInstances(
  [in] IWbemServices   *pNamespace,
  [in] WCHAR           *wszClass,
  [in] long            lFlags,
  [in] IWbemContext    *pCtx,
  [in] IWbemObjectSink *pSink
);