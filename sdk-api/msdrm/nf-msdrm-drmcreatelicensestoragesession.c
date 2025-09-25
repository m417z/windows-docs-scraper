DRMEXPORT HRESULT UDAPICALL DRMCreateLicenseStorageSession(
  [in]  DRMENVHANDLE hEnv,
  [in]  DRMHANDLE    hDefaultLibrary,
  [in]  DRMHSESSION  hClient,
  [in]  UINT         uFlags,
  [in]  PWSTR        wszIssuanceLicense,
  [out] DRMHSESSION  *phLicenseStorage
);