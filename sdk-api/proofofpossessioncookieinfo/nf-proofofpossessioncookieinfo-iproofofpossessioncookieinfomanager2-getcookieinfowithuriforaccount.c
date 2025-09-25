HRESULT GetCookieInfoWithUriForAccount(
  IInspectable                *webAccount,
  LPCWSTR                     uri,
  DWORD                       *cookieInfoCount,
  ProofOfPossessionCookieInfo **cookieInfo
);