NTDSAPI DWORD DsInheritSecurityIdentityW(
  [in] HANDLE  hDS,
  [in] DWORD   Flags,
  [in] LPCWSTR SrcPrincipal,
  [in] LPCWSTR DstPrincipal
);