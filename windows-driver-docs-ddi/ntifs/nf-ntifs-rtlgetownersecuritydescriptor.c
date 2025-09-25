NTSYSAPI NTSTATUS RtlGetOwnerSecurityDescriptor(
  [in]  PSECURITY_DESCRIPTOR SecurityDescriptor,
  [out] PSID                 *Owner,
  [out] PBOOLEAN             OwnerDefaulted
);