typedef struct {
  unsigned long Version;
  RPC_CSTR      ProtSeq;
  RPC_CSTR      Endpoint;
  void          *SecurityDescriptor;
  unsigned long Backlog;
} RPC_ENDPOINT_TEMPLATEA, *PRPC_ENDPOINT_TEMPLATEA;