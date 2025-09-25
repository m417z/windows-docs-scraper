HRESULT Open(
  [in]           const WCHAR              *pwszMethod,
  [in]           const WCHAR              *pwszUrl,
  [in, optional] IXMLHTTPRequest2Callback *pStatusCallback,
  [in, optional] const WCHAR              *pwszUserName,
  [in, optional] const WCHAR              *pwszPassword,
  [in, optional] const WCHAR              *pwszProxyUserName,
  [in, optional] const WCHAR              *pwszProxyPassword
);