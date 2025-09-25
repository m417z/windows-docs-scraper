HRESULT CoQueryProxyBlanket(
  [in]            IUnknown                 *pProxy,
  [out, optional] DWORD                    *pwAuthnSvc,
  [out, optional] DWORD                    *pAuthzSvc,
  [out, optional] LPOLESTR                 *pServerPrincName,
  [out, optional] DWORD                    *pAuthnLevel,
  [out, optional] DWORD                    *pImpLevel,
  [out, optional] RPC_AUTH_IDENTITY_HANDLE *pAuthInfo,
  [out, optional] DWORD                    *pCapabilites
);