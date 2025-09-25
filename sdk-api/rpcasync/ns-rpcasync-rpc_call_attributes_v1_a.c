typedef struct tagRPC_CALL_ATTRIBUTES_V1_A {
  unsigned int  Version;
  unsigned long Flags;
  unsigned long ServerPrincipalNameBufferLength;
  unsigned char *ServerPrincipalName;
  unsigned long ClientPrincipalNameBufferLength;
  unsigned char *ClientPrincipalName;
  unsigned long AuthenticationLevel;
  unsigned long AuthenticationService;
  BOOL          NullSession;
} RPC_CALL_ATTRIBUTES_V1_A;