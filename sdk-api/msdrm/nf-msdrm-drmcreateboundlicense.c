DRMEXPORT HRESULT UDAPICALL DRMCreateBoundLicense(
  [in]  DRMENVHANDLE          hEnv,
  [in]  DRMBOUNDLICENSEPARAMS *pParams,
  [in]  PWSTR                 wszLicenseChain,
  [out] DRMHANDLE             *phBoundLicense,
  [out] DRMHANDLE             *phErrorLog
);