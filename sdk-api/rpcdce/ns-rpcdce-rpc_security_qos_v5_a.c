typedef struct _RPC_SECURITY_QOS_V5_A {
  unsigned long Version;
  unsigned long Capabilities;
  unsigned long IdentityTracking;
  unsigned long ImpersonationType;
  unsigned long AdditionalSecurityInfoType;
  union {
    RPC_HTTP_TRANSPORT_CREDENTIALS_A *HttpCredentials;
  } u;
  void          *Sid;
  unsigned int  EffectiveOnly;
  void          *ServerSecurityDescriptor;
} RPC_SECURITY_QOS_V5_A, *PRPC_SECURITY_QOS_V5_A;