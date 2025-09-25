NTDSAPI DWORD DsBindWithCredW(
  [in, optional] LPCWSTR                  DomainControllerName,
  [in, optional] LPCWSTR                  DnsDomainName,
  [in, optional] RPC_AUTH_IDENTITY_HANDLE AuthIdentity,
  [out]          HANDLE                   *phDS
);