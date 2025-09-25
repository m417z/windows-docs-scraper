typedef struct tagEapHostPeerMethodResult {
  BOOL            fIsSuccess;
  UINT32          dwFailureReasonCode;
  BOOL            fSaveConnectionData;
  UINT32          dwSizeofConnectionData;
#if ...
  BYTE            *pConnectionData;
#else
  BYTE            *pConnectionData;
#endif
  BOOL            fSaveUserData;
  UINT32          dwSizeofUserData;
#if ...
  BYTE            *pUserData;
#else
  BYTE            *pUserData;
#endif
  EAP_ATTRIBUTES  *pAttribArray;
  ISOLATION_STATE isolationState;
  EAP_METHOD_INFO *pEapMethodInfo;
  EAP_ERROR       *pEapError;
} EapHostPeerMethodResult;