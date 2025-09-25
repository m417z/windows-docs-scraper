WINHTTPAPI BOOL WinHttpGetProxyForUrl(
  [in]  HINTERNET                 hSession,
  [in]  LPCWSTR                   lpcwszUrl,
  [in]  WINHTTP_AUTOPROXY_OPTIONS *pAutoProxyOptions,
  [out] WINHTTP_PROXY_INFO        *pProxyInfo
);