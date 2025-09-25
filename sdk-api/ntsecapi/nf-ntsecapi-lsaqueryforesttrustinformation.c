NTSTATUS LsaQueryForestTrustInformation(
  [in]  LSA_HANDLE                    PolicyHandle,
  [in]  PLSA_UNICODE_STRING           TrustedDomainName,
  [out] PLSA_FOREST_TRUST_INFORMATION *ForestTrustInfo
);