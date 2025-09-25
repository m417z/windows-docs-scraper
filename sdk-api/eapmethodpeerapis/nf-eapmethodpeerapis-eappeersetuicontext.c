DWORD EapPeerSetUIContext(
  [in]  EAP_SESSION_HANDLE  sessionHandle,
  [in]  DWORD               dwSizeOfUIContextData,
  [in]  const BYTE          *pUIContextData,
  [in]  EapPeerMethodOutput *pEapOutput,
  [out] EAP_ERROR           **ppEapError
);