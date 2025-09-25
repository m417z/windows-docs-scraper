HRESULT CoInitializeSecurity(
  [in, optional] PSECURITY_DESCRIPTOR        pSecDesc,
  [in]           LONG                        cAuthSvc,
  [in, optional] SOLE_AUTHENTICATION_SERVICE *asAuthSvc,
  [in, optional] void                        *pReserved1,
  [in]           DWORD                       dwAuthnLevel,
  [in]           DWORD                       dwImpLevel,
  [in, optional] void                        *pAuthList,
  [in]           DWORD                       dwCapabilities,
  [in, optional] void                        *pReserved3
);