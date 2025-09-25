DWORD EapMethodAuthenticatorReceivePacket(
  [in]  EAP_SESSION_HANDLE                       sessionHandle,
  [in]  DWORD                                    cbReceivePacket,
  [in]  const EapPacket * const                  pReceivePacket,
  [out] EAP_METHOD_AUTHENTICATOR_RESPONSE_ACTION *pEapOutput,
  [out] EAP_ERROR                                **ppEapError
);