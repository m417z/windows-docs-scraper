NTDSAPI DWORD DsAddSidHistoryA(
  [in] HANDLE                   hDS,
  [in] DWORD                    Flags,
  [in] LPCSTR                   SrcDomain,
  [in] LPCSTR                   SrcPrincipal,
  [in] LPCSTR                   SrcDomainController,
  [in] RPC_AUTH_IDENTITY_HANDLE SrcDomainCreds,
  [in] LPCSTR                   DstDomain,
  [in] LPCSTR                   DstPrincipal
);