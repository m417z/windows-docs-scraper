BOOL ConvertStringSecurityDescriptorToSecurityDescriptorW(
  [in]  LPCWSTR              StringSecurityDescriptor,
  [in]  DWORD                StringSDRevision,
  [out] PSECURITY_DESCRIPTOR *SecurityDescriptor,
  [out] PULONG               SecurityDescriptorSize
);