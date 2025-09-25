NTDSAPI_POSTXP DWORD DsBindWithSpnExW(
  [in, optional] LPCWSTR                  DomainControllerName,
  [in, optional] LPCWSTR                  DnsDomainName,
  [in, optional] RPC_AUTH_IDENTITY_HANDLE AuthIdentity,
  [in, optional] LPCWSTR                  ServicePrincipalName,
  [in, optional] DWORD                    BindFlags,
  [out]          HANDLE                   *phDS
);