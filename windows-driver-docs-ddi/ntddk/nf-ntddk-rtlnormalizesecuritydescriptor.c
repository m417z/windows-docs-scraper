NTSYSAPI BOOLEAN RtlNormalizeSecurityDescriptor(
  PSECURITY_DESCRIPTOR *SecurityDescriptor,
  ULONG                SecurityDescriptorLength,
  PSECURITY_DESCRIPTOR *NewSecurityDescriptor,
  PULONG               NewSecurityDescriptorLength,
  BOOLEAN              CheckOnly
);