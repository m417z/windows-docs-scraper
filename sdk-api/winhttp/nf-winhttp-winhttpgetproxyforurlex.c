WINHTTPAPI DWORD WinHttpGetProxyForUrlEx(
  [in] HINTERNET                 hResolver,
  [in] PCWSTR                    pcwszUrl,
  [in] WINHTTP_AUTOPROXY_OPTIONS *pAutoProxyOptions,
  [in] DWORD_PTR                 pContext
);