typedef struct _SOCKET_SECURITY_QUERY_TEMPLATE {
  SOCKET_SECURITY_PROTOCOL SecurityProtocol;
  SOCKADDR_STORAGE         PeerAddress;
  ULONG                    PeerTokenAccessMask;
} SOCKET_SECURITY_QUERY_TEMPLATE;