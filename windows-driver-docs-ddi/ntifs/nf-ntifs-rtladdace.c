NTSYSAPI NTSTATUS RtlAddAce(
  [in, out] PACL  Acl,
  [in]      ULONG AceRevision,
  [in]      ULONG StartingAceIndex,
  [in]      PVOID AceList,
  [in]      ULONG AceListLength
);