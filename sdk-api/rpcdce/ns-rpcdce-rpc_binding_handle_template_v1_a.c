typedef struct _RPC_BINDING_HANDLE_TEMPLATE_V1_A {
  unsigned long Version;
  unsigned long Flags;
  unsigned long ProtocolSequence;
  unsigned char *NetworkAddress;
  unsigned char *StringEndpoint;
  union {
    unsigned char *Reserved;
  } u1;
  UUID          ObjectUuid;
} RPC_BINDING_HANDLE_TEMPLATE_V1_A, *PRPC_BINDING_HANDLE_TEMPLATE_V1_A;