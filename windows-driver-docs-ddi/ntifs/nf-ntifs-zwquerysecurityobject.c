NTSYSAPI NTSTATUS ZwQuerySecurityObject(
  [in]  HANDLE               Handle,
  [in]  SECURITY_INFORMATION SecurityInformation,
  [out] PSECURITY_DESCRIPTOR SecurityDescriptor,
  [in]  ULONG                Length,
  [out] PULONG               LengthNeeded
);