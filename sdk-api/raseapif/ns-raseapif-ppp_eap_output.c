typedef struct _PPP_EAP_OUTPUT {
  DWORD              dwSizeInBytes;
  PPP_EAP_ACTION     Action;
  DWORD              dwAuthResultCode;
  RAS_AUTH_ATTRIBUTE *pUserAttributes;
  BOOL               fInvokeInteractiveUI;
  PBYTE              pUIContextData;
  DWORD              dwSizeOfUIContextData;
  BOOL               fSaveConnectionData;
  PBYTE              pConnectionData;
  DWORD              dwSizeOfConnectionData;
  BOOL               fSaveUserData;
  PBYTE              pUserData;
  DWORD              dwSizeOfUserData;
  NgcTicketContext   *pNgcKerbTicket;
  BOOL               fSaveToCredMan;
} PPP_EAP_OUTPUT, *PPPP_EAP_OUTPUT;