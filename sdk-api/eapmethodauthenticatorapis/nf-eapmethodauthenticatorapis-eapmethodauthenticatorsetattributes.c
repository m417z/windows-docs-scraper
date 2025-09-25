DWORD EapMethodAuthenticatorSetAttributes(
  [in]  EAP_SESSION_HANDLE                       sessionHandle,
  [in]  const EapAttributes * const              pAttribs,
  [out] EAP_METHOD_AUTHENTICATOR_RESPONSE_ACTION *pEapOutput,
  [out] EAP_ERROR                                **ppEapError
);