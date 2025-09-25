__kernel_entry NTSYSCALLAPI NTSTATUS NtSetSecurityObject(
  [in] HANDLE               Handle,
  [in] SECURITY_INFORMATION SecurityInformation,
  [in] PSECURITY_DESCRIPTOR SecurityDescriptor
);