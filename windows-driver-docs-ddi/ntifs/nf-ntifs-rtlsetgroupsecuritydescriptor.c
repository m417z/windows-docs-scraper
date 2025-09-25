NTSYSAPI NTSTATUS RtlSetGroupSecurityDescriptor(
  [in, out]      PSECURITY_DESCRIPTOR SecurityDescriptor,
  [in, optional] PSID                 Group,
  [in, optional] BOOLEAN              GroupDefaulted
);