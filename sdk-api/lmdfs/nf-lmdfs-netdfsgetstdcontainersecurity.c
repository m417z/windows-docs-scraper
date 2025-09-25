NET_API_STATUS NET_API_FUNCTION NetDfsGetStdContainerSecurity(
  [in]  LPWSTR               MachineName,
  [in]  SECURITY_INFORMATION SecurityInformation,
  [out] PSECURITY_DESCRIPTOR *ppSecurityDescriptor,
  [out] LPDWORD              lpcbSecurityDescriptor
);