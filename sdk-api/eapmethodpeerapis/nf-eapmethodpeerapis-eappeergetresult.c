DWORD EapPeerGetResult(
  [in]  EAP_SESSION_HANDLE        sessionHandle,
  [in]  EapPeerMethodResultReason reason,
        EapPeerMethodResult       *pResult,
  [out] EAP_ERROR                 **ppEapError
);