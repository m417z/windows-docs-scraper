NTSYSAPI NTSTATUS RtlAddAccessAllowedAceEx(
  [in, out] PACL        Acl,
  [in]      ULONG       AceRevision,
  [in]      ULONG       AceFlags,
  [in]      ACCESS_MASK AccessMask,
  [in]      PSID        Sid
);