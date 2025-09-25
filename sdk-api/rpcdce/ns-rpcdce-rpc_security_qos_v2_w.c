typedef struct _RPC_SECURITY_QOS_V2_W {
  unsigned long Version;
  unsigned long Capabilities;
  unsigned long IdentityTracking;
  unsigned long ImpersonationType;
  unsigned long AdditionalSecurityInfoType;
  union {
    RPC_HTTP_TRANSPORT_CREDENTIALS_W *HttpCredentials;
  } u;
} RPC_SECURITY_QOS_V2_W, *PRPC_SECURITY_QOS_V2_W;