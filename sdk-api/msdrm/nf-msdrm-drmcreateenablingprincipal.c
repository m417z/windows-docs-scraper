DRMEXPORT HRESULT UDAPICALL DRMCreateEnablingPrincipal(
  [in]  DRMENVHANDLE hEnv,
  [in]  DRMHANDLE    hLibrary,
  [in]  PWSTR        wszObject,
  [in]  DRMID        *pidPrincipal,
  [in]  PWSTR        wszCredentials,
  [out] DRMHANDLE    *phEnablingPrincipal
);