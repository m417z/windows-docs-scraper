NET_API_STATUS NET_API_FUNCTION NetDfsGetFtContainerSecurity(
  [in]  LPWSTR               DomainName,
  [in]  SECURITY_INFORMATION SecurityInformation,
  [out] PSECURITY_DESCRIPTOR *ppSecurityDescriptor,
  [out] LPDWORD              lpcbSecurityDescriptor
);