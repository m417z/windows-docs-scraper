DWORD EapHostPeerProcessReceivedPacket(
  [in]  EAP_SESSIONID             sessionHandle,
  [in]  DWORD                     cbReceivePacket,
  [in]  const BYTE * const        pReceivePacket,
  [out] EapHostPeerResponseAction *pEapOutput,
  [out] EAP_ERROR                 **ppEapError
);