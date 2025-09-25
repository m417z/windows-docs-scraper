NTSYSAPI NTSTATUS RtlAllocateAndInitializeSid(
  PSID_IDENTIFIER_AUTHORITY IdentifierAuthority,
  UCHAR                     SubAuthorityCount,
  ULONG                     SubAuthority0,
  ULONG                     SubAuthority1,
  ULONG                     SubAuthority2,
  ULONG                     SubAuthority3,
  ULONG                     SubAuthority4,
  ULONG                     SubAuthority5,
  ULONG                     SubAuthority6,
  ULONG                     SubAuthority7,
  PSID                      *Sid
);