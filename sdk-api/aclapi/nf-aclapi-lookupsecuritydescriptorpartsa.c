DWORD LookupSecurityDescriptorPartsA(
  [out, optional] PTRUSTEE_A           *ppOwner,
  [out, optional] PTRUSTEE_A           *ppGroup,
  [out, optional] PULONG               pcCountOfAccessEntries,
  [out, optional] PEXPLICIT_ACCESS_A   *ppListOfAccessEntries,
  [out, optional] PULONG               pcCountOfAuditEntries,
  [out, optional] PEXPLICIT_ACCESS_A   *ppListOfAuditEntries,
  [in]            PSECURITY_DESCRIPTOR pSD
);