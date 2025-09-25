DWORD FwpmEngineOpen0(
  [in, optional] const wchar_t             *serverName,
  [in]           UINT32                    authnService,
  [in, optional] SEC_WINNT_AUTH_IDENTITY_W *authIdentity,
  [in, optional] const FWPM_SESSION0       *session,
  [out]          HANDLE                    *engineHandle
);