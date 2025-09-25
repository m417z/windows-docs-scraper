LONG ClusterRegGetKeySecurity(
  [in]      HKEY                 hKey,
  [in]      SECURITY_INFORMATION RequestedInformation,
  [out]     PSECURITY_DESCRIPTOR pSecurityDescriptor,
  [in, out] LPDWORD              lpcbSecurityDescriptor
);