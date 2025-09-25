DWORD EapHostPeerSetUIContext(
  [in]  EAP_SESSIONID             sessionHandle,
  [in]  DWORD                     dwSizeOfUIContextData,
  [in]  const BYTE * const        pUIContextData,
  [out] EapHostPeerResponseAction *pEapOutput,
  [out] EAP_ERROR                 **ppEapError
);