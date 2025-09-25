NTDSAPI_POSTXP DWORD DsBindByInstanceA(
  [in]           LPCSTR                   ServerName,
  [in]           LPCSTR                   Annotation,
  [in]           GUID                     *InstanceGuid,
  [in]           LPCSTR                   DnsDomainName,
  [in, optional] RPC_AUTH_IDENTITY_HANDLE AuthIdentity,
  [in, optional] LPCSTR                   ServicePrincipalName,
  [in, optional] DWORD                    BindFlags,
  [out]          HANDLE                   *phDS
);