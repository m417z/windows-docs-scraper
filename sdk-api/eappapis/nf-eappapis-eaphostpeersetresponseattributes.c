DWORD EapHostPeerSetResponseAttributes(
  [in]  EAP_SESSIONID               sessionHandle,
  [in]  const EapAttributes * const pAttribs,
  [out] EapHostPeerResponseAction   *pEapOutput,
  [out] EAP_ERROR                   **ppEapError
);