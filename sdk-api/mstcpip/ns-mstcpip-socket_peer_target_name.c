typedef struct _SOCKET_PEER_TARGET_NAME {
  SOCKET_SECURITY_PROTOCOL SecurityProtocol;
  SOCKADDR_STORAGE         PeerAddress;
  ULONG                    PeerTargetNameStringLen;
  wchar_t                  AllStrings[0];
} SOCKET_PEER_TARGET_NAME;