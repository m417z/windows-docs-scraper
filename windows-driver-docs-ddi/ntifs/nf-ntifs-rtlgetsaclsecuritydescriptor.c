NTSYSAPI NTSTATUS RtlGetSaclSecurityDescriptor(
  [in]  PSECURITY_DESCRIPTOR SecurityDescriptor,
  [out] PBOOLEAN             SaclPresent,
  [out] PACL                 *Sacl,
  [out] PBOOLEAN             SaclDefaulted
);