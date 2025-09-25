typedef struct {
  unsigned long Version;
  RPC_CSTR      ProtSeq;
  RPC_CSTR      Endpoint;
  void          *SecurityDescriptor;
  unsigned long Backlog;
} RPC_ENDPOINT_TEMPLATE, *PRPC_ENDPOINT_TEMPLATE;