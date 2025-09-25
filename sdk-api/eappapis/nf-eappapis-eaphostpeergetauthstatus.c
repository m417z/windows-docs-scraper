DWORD EapHostPeerGetAuthStatus(
  [in]  EAP_SESSIONID         sessionHandle,
  [in]  EapHostPeerAuthParams authParam,
  [out] DWORD                 *pcbAuthData,
  [out] BYTE                  **ppAuthData,
  [out] EAP_ERROR             **ppEapError
);