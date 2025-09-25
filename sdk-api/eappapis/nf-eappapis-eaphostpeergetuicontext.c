DWORD EapHostPeerGetUIContext(
  [in]  EAP_SESSIONID sessionHandle,
  [out] DWORD         *pdwSizeOfUIContextData,
  [out] BYTE          **ppUIContextData,
  [out] EAP_ERROR     **ppEapError
);