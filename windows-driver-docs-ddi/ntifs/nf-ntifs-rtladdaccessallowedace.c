NTSYSAPI NTSTATUS RtlAddAccessAllowedAce(
  [in, out] PACL        Acl,
  [in]      ULONG       AceRevision,
  [in]      ACCESS_MASK AccessMask,
  [in]      PSID        Sid
);