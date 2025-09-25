BOOL ConvertSecurityDescriptorToStringSecurityDescriptorW(
  [in]  PSECURITY_DESCRIPTOR SecurityDescriptor,
  [in]  DWORD                RequestedStringSDRevision,
  [in]  SECURITY_INFORMATION SecurityInformation,
  [out] LPWSTR               *StringSecurityDescriptor,
  [out] PULONG               StringSecurityDescriptorLen
);