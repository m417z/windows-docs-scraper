NTSYSAPI NTSTATUS RtlSetOwnerSecurityDescriptor(
  [in, out]      PSECURITY_DESCRIPTOR SecurityDescriptor,
  [in, optional] PSID                 Owner,
  [in, optional] BOOLEAN              OwnerDefaulted
);