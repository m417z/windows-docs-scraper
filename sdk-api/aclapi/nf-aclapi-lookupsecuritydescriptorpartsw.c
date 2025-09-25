DWORD LookupSecurityDescriptorPartsW(
  [out, optional] PTRUSTEE_W           *ppOwner,
  [out, optional] PTRUSTEE_W           *ppGroup,
  [out, optional] PULONG               pcCountOfAccessEntries,
  [out, optional] PEXPLICIT_ACCESS_W   *ppListOfAccessEntries,
  [out, optional] PULONG               pcCountOfAuditEntries,
  [out, optional] PEXPLICIT_ACCESS_W   *ppListOfAuditEntries,
  [in]            PSECURITY_DESCRIPTOR pSD
);