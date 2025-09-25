NTDSAPI_POSTXP DWORD DsBindByInstanceW(
  [in]           LPCWSTR                  ServerName,
  [in]           LPCWSTR                  Annotation,
  [in]           GUID                     *InstanceGuid,
  [in]           LPCWSTR                  DnsDomainName,
  [in, optional] RPC_AUTH_IDENTITY_HANDLE AuthIdentity,
  [in, optional] LPCWSTR                  ServicePrincipalName,
  [in, optional] DWORD                    BindFlags,
  [out]          HANDLE                   *phDS
);