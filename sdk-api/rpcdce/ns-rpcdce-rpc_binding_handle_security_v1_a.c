typedef struct _RPC_BINDING_HANDLE_SECURITY_V1_A {
  unsigned long             Version;
  unsigned char             *ServerPrincName;
  unsigned long             AuthnLevel;
  unsigned long             AuthnSvc;
  SEC_WINNT_AUTH_IDENTITY_A *AuthIdentity;
  RPC_SECURITY_QOS          *SecurityQos;
} RPC_BINDING_HANDLE_SECURITY_V1_A, *PRPC_BINDING_HANDLE_SECURITY_V1_A;