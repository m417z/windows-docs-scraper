NTSYSAPI NTSTATUS RtlGetDaclSecurityDescriptor(
  [in]  PSECURITY_DESCRIPTOR SecurityDescriptor,
  [out] PBOOLEAN             DaclPresent,
  [out] PACL                 *Dacl,
  [out] PBOOLEAN             DaclDefaulted
);