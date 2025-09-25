BOOL GetPrivateObjectSecurity(
  [in]            PSECURITY_DESCRIPTOR ObjectDescriptor,
  [in]            SECURITY_INFORMATION SecurityInformation,
  [out, optional] PSECURITY_DESCRIPTOR ResultantDescriptor,
  [in]            DWORD                DescriptorLength,
  [out]           PDWORD               ReturnLength
);