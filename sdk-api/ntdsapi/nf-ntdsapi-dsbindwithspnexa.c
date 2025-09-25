NTDSAPI_POSTXP DWORD DsBindWithSpnExA(
  [in, optional] LPCSTR                   DomainControllerName,
  [in, optional] LPCSTR                   DnsDomainName,
  [in, optional] RPC_AUTH_IDENTITY_HANDLE AuthIdentity,
  [in, optional] LPCSTR                   ServicePrincipalName,
  [in, optional] DWORD                    BindFlags,
  [out]          HANDLE                   *phDS
);