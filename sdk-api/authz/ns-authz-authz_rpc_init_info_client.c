typedef struct _AUTHZ_RPC_INIT_INFO_CLIENT {
  USHORT version;
  PWSTR  ObjectUuid;
  PWSTR  ProtSeq;
  PWSTR  NetworkAddr;
  PWSTR  Endpoint;
  PWSTR  Options;
  PWSTR  ServerSpn;
} AUTHZ_RPC_INIT_INFO_CLIENT, *PAUTHZ_RPC_INIT_INFO_CLIENT;