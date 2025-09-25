DWORD EapHostPeerGetResult(
  [in]  EAP_SESSIONID                 sessionHandle,
  [in]  EapHostPeerMethodResultReason reason,
  [out] EapHostPeerMethodResult       *ppResult,
  [out] EAP_ERROR                     **ppEapError
);