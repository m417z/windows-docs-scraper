NTSYSAPI NTSTATUS RtlAbsoluteToSelfRelativeSD(
  [in]      PSECURITY_DESCRIPTOR AbsoluteSecurityDescriptor,
  [out]     PSECURITY_DESCRIPTOR SelfRelativeSecurityDescriptor,
  [in, out] PULONG               BufferLength
);