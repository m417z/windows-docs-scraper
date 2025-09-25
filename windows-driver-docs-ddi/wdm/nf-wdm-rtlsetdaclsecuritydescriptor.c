NTSYSAPI NTSTATUS RtlSetDaclSecurityDescriptor(
  [in, out]      PSECURITY_DESCRIPTOR SecurityDescriptor,
  [in]           BOOLEAN              DaclPresent,
  [in, optional] PACL                 Dacl,
  [in, optional] BOOLEAN              DaclDefaulted
);