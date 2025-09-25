HRESULT CoQueryClientBlanket(
  [out, optional]     DWORD            *pAuthnSvc,
  [out, optional]     DWORD            *pAuthzSvc,
  [out, optional]     LPOLESTR         *pServerPrincName,
  [out, optional]     DWORD            *pAuthnLevel,
  [out, optional]     DWORD            *pImpLevel,
  [out, optional]     RPC_AUTHZ_HANDLE *pPrivs,
  [in, out, optional] DWORD            *pCapabilities
);