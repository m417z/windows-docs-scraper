NTSYSAPI NTSTATUS RtlGetGroupSecurityDescriptor(
  [in]  PSECURITY_DESCRIPTOR SecurityDescriptor,
  [out] PSID                 *Group,
  [out] PBOOLEAN             GroupDefaulted
);