HRESULT GetAllAccessRights(
  [in]  LPWSTR                            lpProperty,
  [out] PACTRL_ACCESSW_ALLOCATE_ALL_NODES *ppAccessList,
  [out] PTRUSTEEW                         *ppOwner,
  [out] PTRUSTEEW                         *ppGroup
);