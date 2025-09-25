HRESULT IsUserAllowedToLogon(
  [in] ULONG      SessionId,
  [in] HANDLE_PTR UserToken,
  [in] WCHAR      *pDomainName,
  [in] WCHAR      *pUserName
);