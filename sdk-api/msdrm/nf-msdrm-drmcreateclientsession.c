DRMEXPORT HRESULT UDAPICALL DRMCreateClientSession(
  [in]           DRMCALLBACK pfnCallback,
  [in]           UINT        uCallbackVersion,
  [in]           PWSTR       wszGroupIDProviderType,
  [in, optional] PWSTR       wszGroupID,
  [out]          DRMHSESSION *phClient
);