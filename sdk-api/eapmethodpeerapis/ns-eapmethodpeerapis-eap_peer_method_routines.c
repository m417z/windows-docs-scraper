typedef struct _EAP_PEER_METHOD_ROUTINES {
  DWORD    dwVersion;
  EAP_TYPE *pEapType;
  DWORD((EAP_ERROR **ppEapError)   * )EapPeerInitialize;
  DWORD(flags,DWORD dwSizeofConnectionData, const BYTE *pConnectionData,DWORD dwSizeofUserData, const BYTE *pUserData,HANDLE hTokenImpersonateUser,BOOL *pfInvokeUI,DWORD *pdwSizeOfUserDataOut,BYTE **ppUserDataOut,LPWSTR *ppwszIdentity,EAP_ERROR **ppEapError)   * )(DWORD EapPeerGetIdentity;
  DWORD(RD dwFlags, const EapAttributes * const pAttributeArray,HANDLE hTokenImpersonateUser,DWORD dwSizeofConnectionData,BYTE *pConnectionData,DWORD dwSizeofUserData,BYTE *pUserData,DWORD dwMaxSendPacketSize,EAP_SESSION_HANDLE *pSessionHandle,EAP_ERROR **ppEapError)   * )(DWOEapPeerBeginSession;
  DWORD(AP_SESSION_HANDLE sessionHandle,WCHAR *pwszIdentity,WCHAR *pwszPassword,EAP_ERROR **ppEapError)   * )(EEapPeerSetCredentials;
  DWORD(AP_SESSION_HANDLE sessionHandle,DWORD cbReceivePacket,EapPacket *pReceivePacket,EapPeerMethodOutput *pEapOutput,EAP_ERROR **ppEapError)   * )(EEapPeerProcessRequestPacket;
  DWORD(AP_SESSION_HANDLE sessionHandle,DWORD *pcbSendPacket,EapPacket *pSendPacket,EAP_ERROR **ppEapError)   * )(EEapPeerGetResponsePacket;
  DWORD(EAP_SESSION_HANDLE sessionHandle,EapPeerMethodResultReason reason,EapPeerMethodResult *pResult,EAP_ERROR **ppEapError)   * )(EapPeerGetResult;
  DWORD(P_SESSION_HANDLE sessionHandle,DWORD *pdwSizeOfUIContextData,BYTE **ppUIContextData,EAP_ERROR **ppEapError)   * )(EAEapPeerGetUIContext;
  DWORD(AP_SESSION_HANDLE sessionHandle,DWORD dwSizeOfUIContextData, const BYTE *pUIContextData,EapPeerMethodOutput *pEapOutput,EAP_ERROR **ppEapError)   * )(EEapPeerSetUIContext;
  DWORD(EAP_SESSION_HANDLE sessionHandle,EapAttributes *pAttribs,EAP_ERROR **ppEapError)   * )(EapPeerGetResponseAttributes;
  DWORD(AP_SESSION_HANDLE sessionHandle,EapAttributes *pAttribs,EapPeerMethodOutput *pEapOutput,EAP_ERROR **ppEapError)   * )(EEapPeerSetResponseAttributes;
  DWORD((EAP_SESSION_HANDLE sessionHandle,EAP_ERROR **ppEapError)   * )EapPeerEndSession;
  DWORD((EAP_ERROR **ppEapError)   * )EapPeerShutdown;
} EAP_PEER_METHOD_ROUTINES;