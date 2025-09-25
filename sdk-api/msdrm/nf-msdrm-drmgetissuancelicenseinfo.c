DRMEXPORT HRESULT UDAPICALL DRMGetIssuanceLicenseInfo(
  [in]      DRMPUBHANDLE hIssuanceLicense,
  [out]     SYSTEMTIME   *pstTimeFrom,
  [out]     SYSTEMTIME   *pstTimeUntil,
  [in]      UINT         uFlags,
  [in, out] UINT         *puDistributionPointNameLength,
  [out]     PWSTR        wszDistributionPointName,
  [in, out] UINT         *puDistributionPointURLLength,
  [out]     PWSTR        wszDistributionPointURL,
  [out]     DRMPUBHANDLE *phOwner,
  [out]     BOOL         *pfOfficial
);