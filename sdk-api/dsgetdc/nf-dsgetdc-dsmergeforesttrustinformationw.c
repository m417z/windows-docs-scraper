DSGETDCAPI DWORD DsMergeForestTrustInformationW(
  [in]           LPCWSTR                       DomainName,
  [in]           PLSA_FOREST_TRUST_INFORMATION NewForestTrustInfo,
  [in, optional] PLSA_FOREST_TRUST_INFORMATION OldForestTrustInfo,
  [out]          PLSA_FOREST_TRUST_INFORMATION *MergedForestTrustInfo
);