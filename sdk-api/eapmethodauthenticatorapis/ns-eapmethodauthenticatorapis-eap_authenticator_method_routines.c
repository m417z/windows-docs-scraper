typedef struct _EAP_AUTHENTICATOR_METHOD_ROUTINES {
  DWORD           dwSizeInBytes;
  EAP_METHOD_TYPE *pEapType;
  DWORD(EAP_METHOD_TYPE *pEapType,EAP_ERROR **ppEapError)          * )(EapMethodAuthenticatorInitialize;
  DWORD(ORD dwFlags,LPCWSTR pwszIdentity, const EapAttributes * const pAttributeArray,DWORD dwSizeofConnectionData, const BYTE * const pConnectionData,DWORD dwMaxSendPacketSize,EAP_SESSION_HANDLE *pSessionHandle,EAP_ERROR **ppEapError)          * )(DWEapMethodAuthenticatorBeginSession;
  DWORD(EAP_SESSION_HANDLE sessionHandle,DWORD dwFlags,LPCWSTR pwszIdentity, const EapAttributes * const pAttributeArray,EAP_ERROR **ppEapError)          * )(EapMethodAuthenticatorUpdateInnerMethodParams;
  DWORD(AP_SESSION_HANDLE sessionHandle,DWORD cbReceivePacket, const EapPacket * const pReceivePacket,EAP_METHOD_AUTHENTICATOR_RESPONSE_ACTION *pEapOutput,EAP_ERROR **ppEapError)          * )(EEapMethodAuthenticatorReceivePacket;
  DWORD(P_SESSION_HANDLE sessionHandle,BYTE bPacketId,DWORD *pcbSendPacket,EapPacket *pSendPacket,EAP_AUTHENTICATOR_SEND_TIMEOUT *pTimeout,EAP_ERROR **ppEapError)          * )(EAEapMethodAuthenticatorSendPacket;
  DWORD(EAP_SESSION_HANDLE sessionHandle,EapAttributes *pAttribs,EAP_ERROR **ppEapError)          * )(EapMethodAuthenticatorGetAttributes;
  DWORD(AP_SESSION_HANDLE sessionHandle, const EapAttributes * const pAttribs,EAP_METHOD_AUTHENTICATOR_RESPONSE_ACTION *pEapOutput,EAP_ERROR **ppEapError)          * )(EEapMethodAuthenticatorSetAttributes;
  DWORD(EAP_SESSION_HANDLE sessionHandle,EAP_METHOD_AUTHENTICATOR_RESULT *pResult,EAP_ERROR **ppEapError)          * )(EapMethodAuthenticatorGetResult;
  DWORD((EAP_SESSION_HANDLE sessionHandle,EAP_ERROR **ppEapError)          * )EapMethodAuthenticatorEndSession;
  DWORD(EAP_METHOD_TYPE *pEapType,EAP_ERROR **ppEapError)          * )(EapMethodAuthenticatorShutdown;
} EAP_AUTHENTICATOR_METHOD_ROUTINES, *PEAP_AUTHENTICATOR_METHOD_ROUTINES;