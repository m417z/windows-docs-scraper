NTDSAPI DWORD DsBindWithSpnW(
  [in, optional] LPCWSTR                  DomainControllerName,
  [in, optional] LPCWSTR                  DnsDomainName,
  [in, optional] RPC_AUTH_IDENTITY_HANDLE AuthIdentity,
  [in, optional] LPCWSTR                  ServicePrincipalName,
  [out]          HANDLE                   *phDS
);