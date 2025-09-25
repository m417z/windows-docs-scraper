NTSYSAPI NTSTATUS RtlInitializeSidEx(
  [out] PSID                      Sid,
  [in]  PSID_IDENTIFIER_AUTHORITY IdentifierAuthority,
  [in]  UCHAR                     SubAuthorityCount,
        ...                       
);