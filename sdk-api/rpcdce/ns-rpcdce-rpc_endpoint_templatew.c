typedef struct {
  unsigned long Version;
  RPC_WSTR      ProtSeq;
  RPC_WSTR      Endpoint;
  void          *SecurityDescriptor;
  unsigned long Backlog;
} RPC_ENDPOINT_TEMPLATEW, *PRPC_ENDPOINT_TEMPLATEW;