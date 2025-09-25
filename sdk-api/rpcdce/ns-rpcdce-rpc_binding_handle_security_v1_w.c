typedef struct _RPC_BINDING_HANDLE_SECURITY_V1_W {
  unsigned long             Version;
  unsigned short            *ServerPrincName;
  unsigned long             AuthnLevel;
  unsigned long             AuthnSvc;
  SEC_WINNT_AUTH_IDENTITY_W *AuthIdentity;
  RPC_SECURITY_QOS          *SecurityQos;
} RPC_BINDING_HANDLE_SECURITY_V1_W, *PRPC_BINDING_HANDLE_SECURITY_V1_W;