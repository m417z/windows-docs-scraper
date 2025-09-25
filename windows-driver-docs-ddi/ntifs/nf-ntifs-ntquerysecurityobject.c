__kernel_entry NTSYSCALLAPI NTSTATUS NtQuerySecurityObject(
  [in]  HANDLE               Handle,
  [in]  SECURITY_INFORMATION SecurityInformation,
  [out] PSECURITY_DESCRIPTOR SecurityDescriptor,
  [in]  ULONG                Length,
  [out] PULONG               LengthNeeded
);