BOOL ConvertSecurityDescriptorToStringSecurityDescriptorA(
  [in]  PSECURITY_DESCRIPTOR SecurityDescriptor,
  [in]  DWORD                RequestedStringSDRevision,
  [in]  SECURITY_INFORMATION SecurityInformation,
  [out] LPSTR                *StringSecurityDescriptor,
  [out] PULONG               StringSecurityDescriptorLen
);