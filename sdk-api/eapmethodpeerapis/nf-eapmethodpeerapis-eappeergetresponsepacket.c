DWORD EapPeerGetResponsePacket(
  [in]      EAP_SESSION_HANDLE sessionHandle,
  [in, out] DWORD              *pcbSendPacket,
  [out]     EapPacket          *pSendPacket,
  [out]     EAP_ERROR          **ppEapError
);