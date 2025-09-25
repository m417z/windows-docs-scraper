DWORD EapMethodAuthenticatorBeginSession(
  [in]  DWORD                       dwFlags,
  [in]  BYTE                        bInitialId,
        LPCWSTR                     pwszIdentity,
  [in]  const EapAttributes * const pAttributeArray,
  [in]  DWORD                       dwSizeofConnectionData,
        const BYTE * const          pConnectionData,
  [in]  DWORD                       dwMaxSendPacketSize,
  [out] EAP_SESSION_HANDLE          *pSessionHandle,
  [out] EAP_ERROR                   **ppEapError
);