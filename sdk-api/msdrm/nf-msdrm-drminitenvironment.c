DRMEXPORT HRESULT UDAPICALL DRMInitEnvironment(
  [in]  DRMSECURITYPROVIDERTYPE eSecurityProviderType,
  [in]  DRMSPECTYPE             eSpecification,
  [in]  PWSTR                   wszSecurityProvider,
  [in]  PWSTR                   wszManifestCredentials,
  [in]  PWSTR                   wszMachineCredentials,
  [out] DRMENVHANDLE            *phEnv,
  [out] DRMHANDLE               *phDefaultLibrary
);