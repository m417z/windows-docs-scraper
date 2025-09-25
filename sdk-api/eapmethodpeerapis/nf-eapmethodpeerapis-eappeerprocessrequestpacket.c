DWORD EapPeerProcessRequestPacket(
  [in]  EAP_SESSION_HANDLE  sessionHandle,
  [in]  DWORD               cbReceivedPacket,
  [in]  EapPacket           *pReceivedPacket,
  [out] EapPeerMethodOutput *pEapOutput,
  [out] EAP_ERROR           **ppEapError
);