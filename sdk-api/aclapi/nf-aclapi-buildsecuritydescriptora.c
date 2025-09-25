DWORD BuildSecurityDescriptorA(
  [in, optional] PTRUSTEE_A           pOwner,
  [in, optional] PTRUSTEE_A           pGroup,
  [in]           ULONG                cCountOfAccessEntries,
  [in, optional] PEXPLICIT_ACCESS_A   pListOfAccessEntries,
  [in]           ULONG                cCountOfAuditEntries,
  [in, optional] PEXPLICIT_ACCESS_A   pListOfAuditEntries,
  [in, optional] PSECURITY_DESCRIPTOR pOldSD,
  [out]          PULONG               pSizeNewSD,
  [out]          PSECURITY_DESCRIPTOR *pNewSD
);