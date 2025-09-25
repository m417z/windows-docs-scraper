NTSYSAPI NTSTATUS RtlSelfRelativeToAbsoluteSD(
  [in]      PSECURITY_DESCRIPTOR SelfRelativeSecurityDescriptor,
  [out]     PSECURITY_DESCRIPTOR AbsoluteSecurityDescriptor,
  [in, out] PULONG               AbsoluteSecurityDescriptorSize,
  [out]     PACL                 Dacl,
  [in, out] PULONG               DaclSize,
  [out]     PACL                 Sacl,
  [in, out] PULONG               SaclSize,
  [out]     PSID                 Owner,
  [in, out] PULONG               OwnerSize,
  [out]     PSID                 PrimaryGroup,
  [in, out] PULONG               PrimaryGroupSize
);