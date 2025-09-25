HRESULT GetTokenAndSignatureWithTokenResult(
  LPCWSTR                msaAccountId,
  LPCWSTR                appSid,
  LPCWSTR                msaTarget,
  LPCWSTR                msaPolicy,
  LPCWSTR                httpMethod,
  LPCWSTR                uri,
  LPCWSTR                headers,
  BYTE                   *body,
  DWORD                  bodySize,
  BOOL                   forceRefresh,
  IXblIdpAuthTokenResult **result
);