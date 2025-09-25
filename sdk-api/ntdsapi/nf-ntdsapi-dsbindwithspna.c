NTDSAPI DWORD DsBindWithSpnA(
  [in, optional] LPCSTR                   DomainControllerName,
  [in, optional] LPCSTR                   DnsDomainName,
  [in, optional] RPC_AUTH_IDENTITY_HANDLE AuthIdentity,
  [in, optional] LPCSTR                   ServicePrincipalName,
  [out]          HANDLE                   *phDS
);