typedef struct tagRPC_CALL_ATTRIBUTES_V1_W {
  unsigned int   Version;
  unsigned long  Flags;
  unsigned long  ServerPrincipalNameBufferLength;
  unsigned short *ServerPrincipalName;
  unsigned long  ClientPrincipalNameBufferLength;
  unsigned short *ClientPrincipalName;
  unsigned long  AuthenticationLevel;
  unsigned long  AuthenticationService;
  BOOL           NullSession;
} RPC_CALL_ATTRIBUTES_V1_W;