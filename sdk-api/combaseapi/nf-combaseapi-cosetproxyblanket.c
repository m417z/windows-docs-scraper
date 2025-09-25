HRESULT CoSetProxyBlanket(
  [in]           IUnknown                 *pProxy,
  [in]           DWORD                    dwAuthnSvc,
  [in]           DWORD                    dwAuthzSvc,
  [in, optional] OLECHAR                  *pServerPrincName,
  [in]           DWORD                    dwAuthnLevel,
  [in]           DWORD                    dwImpLevel,
  [in, optional] RPC_AUTH_IDENTITY_HANDLE pAuthInfo,
  [in]           DWORD                    dwCapabilities
);