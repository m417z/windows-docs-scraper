DRMEXPORT HRESULT UDAPICALL DRMGetSignedIssuanceLicense(
  [in] DRMENVHANDLE hEnv,
  [in] DRMPUBHANDLE hIssuanceLicense,
  [in] UINT         uFlags,
  [in] BYTE         *pbSymKey,
  [in] UINT         cbSymKey,
  [in] PWSTR        wszSymKeyType,
  [in] PWSTR        wszClientLicensorCertificate,
  [in] DRMCALLBACK  pfnCallback,
  [in] PWSTR        wszURL,
  [in] VOID         *pvContext
);