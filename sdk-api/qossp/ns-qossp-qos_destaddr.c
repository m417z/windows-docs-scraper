typedef struct _QOS_DESTADDR {
  QOS_OBJECT_HDR ObjectHdr;
  const sockaddr *SocketAddress;
  struct         sockaddr;
  ULONG          SocketAddressLength;
} QOS_DESTADDR, *LPQOS_DESTADDR;