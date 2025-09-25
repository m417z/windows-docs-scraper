NTSTATUS SeFilterToken(
  [in]           PACCESS_TOKEN     ExistingToken,
  [in]           ULONG             Flags,
  [in, optional] PTOKEN_GROUPS     SidsToDisable,
  [in, optional] PTOKEN_PRIVILEGES PrivilegesToDelete,
  [in, optional] PTOKEN_GROUPS     RestrictedSids,
                 PACCESS_TOKEN     *FilteredToken
);