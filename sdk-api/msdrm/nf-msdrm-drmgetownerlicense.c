DRMEXPORT HRESULT UDAPICALL DRMGetOwnerLicense(
  [in]      DRMPUBHANDLE hIssuanceLicense,
  [in, out] UINT         *puOwnerLicenseLength,
  [out]     PWSTR        wszOwnerLicense
);