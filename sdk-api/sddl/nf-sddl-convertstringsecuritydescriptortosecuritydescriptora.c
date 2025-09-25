BOOL ConvertStringSecurityDescriptorToSecurityDescriptorA(
  [in]  LPCSTR               StringSecurityDescriptor,
  [in]  DWORD                StringSDRevision,
  [out] PSECURITY_DESCRIPTOR *SecurityDescriptor,
  [out] PULONG               SecurityDescriptorSize
);