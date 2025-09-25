NTSTATUS LsaSetForestTrustInformation(
  [in]  LSA_HANDLE                              PolicyHandle,
  [in]  PLSA_UNICODE_STRING                     TrustedDomainName,
  [in]  PLSA_FOREST_TRUST_INFORMATION           ForestTrustInfo,
  [in]  BOOLEAN                                 CheckOnly,
  [out] PLSA_FOREST_TRUST_COLLISION_INFORMATION *CollisionInfo
);