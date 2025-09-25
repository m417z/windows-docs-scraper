NTDSAPI DWORD DsAddSidHistoryW(
  [in] HANDLE                   hDS,
  [in] DWORD                    Flags,
  [in] LPCWSTR                  SrcDomain,
  [in] LPCWSTR                  SrcPrincipal,
  [in] LPCWSTR                  SrcDomainController,
  [in] RPC_AUTH_IDENTITY_HANDLE SrcDomainCreds,
  [in] LPCWSTR                  DstDomain,
  [in] LPCWSTR                  DstPrincipal
);