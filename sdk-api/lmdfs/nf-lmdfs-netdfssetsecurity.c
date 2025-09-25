NET_API_STATUS NET_API_FUNCTION NetDfsSetSecurity(
  [in] LPWSTR               DfsEntryPath,
  [in] SECURITY_INFORMATION SecurityInformation,
  [in] PSECURITY_DESCRIPTOR pSecurityDescriptor
);