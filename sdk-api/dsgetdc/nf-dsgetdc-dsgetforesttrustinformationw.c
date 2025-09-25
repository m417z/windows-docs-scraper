DSGETDCAPI DWORD DsGetForestTrustInformationW(
  [in, optional] LPCWSTR                       ServerName,
  [in, optional] LPCWSTR                       TrustedDomainName,
  [in]           DWORD                         Flags,
  [out]          PLSA_FOREST_TRUST_INFORMATION *ForestTrustInfo
);