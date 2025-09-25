NTDSAPI DWORD DsBindWithCredA(
  [in, optional] LPCSTR                   DomainControllerName,
  [in, optional] LPCSTR                   DnsDomainName,
  [in, optional] RPC_AUTH_IDENTITY_HANDLE AuthIdentity,
  [out]          HANDLE                   *phDS
);