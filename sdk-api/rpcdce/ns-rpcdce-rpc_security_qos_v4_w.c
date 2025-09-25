typedef struct _RPC_SECURITY_QOS_V4_W {
  unsigned long Version;
  unsigned long Capabilities;
  unsigned long IdentityTracking;
  unsigned long ImpersonationType;
  unsigned long AdditionalSecurityInfoType;
  union {
    RPC_HTTP_TRANSPORT_CREDENTIALS_W *HttpCredentials;
  } u;
  void          *Sid;
  unsigned int  EffectiveOnly;
} RPC_SECURITY_QOS_V4_W, *PRPC_SECURITY_QOS_V4_W;