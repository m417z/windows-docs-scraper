typedef struct tagEapPeerMethodResult {
  BOOL             fIsSuccess;
  DWORD            dwFailureReasonCode;
  BOOL             fSaveConnectionData;
  DWORD            dwSizeofConnectionData;
  BYTE             *pConnectionData;
  BOOL             fSaveUserData;
  DWORD            dwSizeofUserData;
  BYTE             *pUserData;
  EAP_ATTRIBUTES   *pAttribArray;
  EAP_ERROR        *pEapError;
  NgcTicketContext *pNgcKerbTicket;
  BOOL             fSaveToCredMan;
} EapPeerMethodResult;