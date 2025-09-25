DWORD EapHostPeerBeginSession(
  [in]  DWORD                       dwFlags,
  [in]  EAP_METHOD_TYPE             eapType,
  [in]  const EapAttributes * const pAttributeArray,
  [in]  HANDLE                      hTokenImpersonateUser,
  [in]  DWORD                       dwSizeofConnectionData,
  [in]  const BYTE * const          pConnectionData,
  [in]  DWORD                       dwSizeofUserData,
  [in]  const BYTE * const          pUserData,
  [in]  DWORD                       dwMaxSendPacketSize,
  [in]  const GUID * const          pConnectionId,
  [in]  NotificationHandler         func,
  [in]  void                        *pContextData,
  [out] EAP_SESSIONID               *pSessionId,
  [out] EAP_ERROR                   **ppEapError
);