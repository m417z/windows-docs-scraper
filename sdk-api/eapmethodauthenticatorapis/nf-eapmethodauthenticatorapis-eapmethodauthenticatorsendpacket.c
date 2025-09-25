DWORD EapMethodAuthenticatorSendPacket(
  [in]      EAP_SESSION_HANDLE             sessionHandle,
  [in]      BYTE                           bPacketId,
  [in, out] DWORD                          *pcbSendPacket,
  [out]     EapPacket                      *pSendPacket,
  [out]     EAP_AUTHENTICATOR_SEND_TIMEOUT *pTimeout,
  [out]     EAP_ERROR                      **ppEapError
);