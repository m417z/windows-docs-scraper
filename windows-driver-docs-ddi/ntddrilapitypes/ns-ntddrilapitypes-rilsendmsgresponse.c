typedef struct RILSENDMSGRESPONSE {
  DWORD   cbSize;
  DWORD   dwParams;
  HRESULT hrReturn;
  DWORD   dwCDMACauseCode;
  DWORD   dwCDMAErrorClass;
  DWORD   dwGWLTransportCode;
  DWORD   dwGWLRelayCode;
  DWORD   dwMsgID;
} RILSENDMSGRESPONSE, *LPRILSENDMSGRESPONSE;