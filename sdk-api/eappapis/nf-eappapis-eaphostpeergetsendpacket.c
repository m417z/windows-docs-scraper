DWORD EapHostPeerGetSendPacket(
  [in]  EAP_SESSIONID sessionHandle,
  [out] DWORD         *pcbSendPacket,
  [out] BYTE          **ppSendPacket,
  [out] EAP_ERROR     **ppEapError
);