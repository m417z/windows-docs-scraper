NET_API_STATUS NET_API_FUNCTION NetDfsGetSecurity(
  [in]  LPWSTR               DfsEntryPath,
  [in]  SECURITY_INFORMATION SecurityInformation,
  [out] PSECURITY_DESCRIPTOR *ppSecurityDescriptor,
  [out] LPDWORD              lpcbSecurityDescriptor
);