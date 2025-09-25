DRMEXPORT HRESULT UDAPICALL DRMGetSignedIssuanceLicenseEx(
  [in] DRMENVHANDLE hEnv,
  [in] DRMPUBHANDLE hIssuanceLicense,
  [in] UINT         uFlags,
  [in] BYTE         *pbSymKey,
  [in] UINT         cbSymKey,
  [in] PWSTR        wszSymKeyType,
  [in] PVOID        pvReserved,
  [in] DRMHANDLE    hEnablingPrincipal,
  [in] DRMHANDLE    hBoundLicenseCLC,
  [in] DRMCALLBACK  pfnCallback,
  [in] PVOID        pvContext
);