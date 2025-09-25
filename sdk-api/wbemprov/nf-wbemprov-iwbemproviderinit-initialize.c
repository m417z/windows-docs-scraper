HRESULT Initialize(
  [in] LPWSTR                wszUser,
  [in] LONG                  lFlags,
  [in] LPWSTR                wszNamespace,
  [in] LPWSTR                wszLocale,
  [in] IWbemServices         *pNamespace,
  [in] IWbemContext          *pCtx,
  [in] IWbemProviderInitSink *pInitSink
);