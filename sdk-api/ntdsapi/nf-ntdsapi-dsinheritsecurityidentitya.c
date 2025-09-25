NTDSAPI DWORD DsInheritSecurityIdentityA(
  [in] HANDLE hDS,
  [in] DWORD  Flags,
  [in] LPCSTR SrcPrincipal,
  [in] LPCSTR DstPrincipal
);