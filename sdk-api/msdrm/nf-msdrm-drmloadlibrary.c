DRMEXPORT HRESULT UDAPICALL DRMLoadLibrary(
  [in]  DRMENVHANDLE hEnv,
  [in]  DRMSPECTYPE  eSpecification,
  [in]  PWSTR        wszLibraryProvider,
  [in]  PWSTR        wszCredentials,
  [out] DRMHANDLE    *phLibrary
);