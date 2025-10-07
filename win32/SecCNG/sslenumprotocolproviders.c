SECURITY_STATUS WINAPI SslEnumProtocolProviders(
  _Out_ DWORD              *pdwProviderCount,
  _Out_ NCryptProviderName **ppProviderList,
  _In_  DWORD              dwFlags
);