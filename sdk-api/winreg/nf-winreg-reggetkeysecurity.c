LSTATUS RegGetKeySecurity(
  [in]            HKEY                 hKey,
  [in]            SECURITY_INFORMATION SecurityInformation,
  [out, optional] PSECURITY_DESCRIPTOR pSecurityDescriptor,
  [in, out]       LPDWORD              lpcbSecurityDescriptor
);