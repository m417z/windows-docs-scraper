DWORD EapPeerBeginSession(
  [in]  DWORD                       dwFlags,
  [in]  const EapAttributes * const pAttributeArray,
  [in]  HANDLE                      hTokenImpersonateUser,
  [in]  DWORD                       dwSizeofConnectionData,
  [in]  BYTE                        *pConnectionData,
  [in]  DWORD                       dwSizeofUserData,
  [in]  BYTE                        *pUserData,
  [in]  DWORD                       dwMaxSendPacketSize,
  [out] EAP_SESSION_HANDLE          *pSessionHandle,
  [out] EAP_ERROR                   **ppEapError
);