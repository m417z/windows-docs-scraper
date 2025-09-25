DRMEXPORT HRESULT UDAPICALL DRMCreateIssuanceLicense(
  [in]           SYSTEMTIME   *pstTimeFrom,
  [in]           SYSTEMTIME   *pstTimeUntil,
  [in]           PWSTR        wszReferralInfoName,
  [in]           PWSTR        wszReferralInfoURL,
  [in, optional] DRMPUBHANDLE hOwner,
  [in]           PWSTR        wszIssuanceLicense,
  [in]           DRMHANDLE    hBoundLicense,
  [out]          DRMPUBHANDLE *phIssuanceLicense
);