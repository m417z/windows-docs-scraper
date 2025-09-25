typedef struct _RPC_BINDING_HANDLE_TEMPLATE_V1_W {
  unsigned long  Version;
  unsigned long  Flags;
  unsigned long  ProtocolSequence;
  unsigned short *NetworkAddress;
  unsigned short *StringEndpoint;
  union {
    unsigned short *Reserved;
  } u1;
  UUID           ObjectUuid;
} RPC_BINDING_HANDLE_TEMPLATE_V1_W, *PRPC_BINDING_HANDLE_TEMPLATE_V1_W;