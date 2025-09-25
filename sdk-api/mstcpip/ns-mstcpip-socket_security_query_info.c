typedef struct _SOCKET_SECURITY_QUERY_INFO {
  SOCKET_SECURITY_PROTOCOL SecurityProtocol;
  ULONG                    Flags;
  UINT64                   PeerApplicationAccessTokenHandle;
  UINT64                   PeerMachineAccessTokenHandle;
} SOCKET_SECURITY_QUERY_INFO;