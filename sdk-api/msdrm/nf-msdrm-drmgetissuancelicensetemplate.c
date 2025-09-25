DRMEXPORT HRESULT UDAPICALL DRMGetIssuanceLicenseTemplate(
  [in]      DRMPUBHANDLE hIssuanceLicense,
  [in, out] UINT         *puIssuanceLicenseTemplateLength,
  [out]     PWSTR        wszIssuanceLicenseTemplate
);