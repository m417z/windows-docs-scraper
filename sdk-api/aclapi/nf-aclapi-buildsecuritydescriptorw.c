DWORD BuildSecurityDescriptorW(
  [in, optional] PTRUSTEE_W           pOwner,
  [in, optional] PTRUSTEE_W           pGroup,
  [in]           ULONG                cCountOfAccessEntries,
  [in, optional] PEXPLICIT_ACCESS_W   pListOfAccessEntries,
  [in]           ULONG                cCountOfAuditEntries,
  [in, optional] PEXPLICIT_ACCESS_W   pListOfAuditEntries,
  [in, optional] PSECURITY_DESCRIPTOR pOldSD,
  [out]          PULONG               pSizeNewSD,
  [out]          PSECURITY_DESCRIPTOR *pNewSD
);