NTSTATUS SeQuerySecurityDescriptorInfo(
  [in]      PSECURITY_INFORMATION SecurityInformation,
  [out]     PSECURITY_DESCRIPTOR  SecurityDescriptor,
  [in, out] PULONG                Length,
  [in, out] PSECURITY_DESCRIPTOR  *ObjectsSecurityDescriptor
);