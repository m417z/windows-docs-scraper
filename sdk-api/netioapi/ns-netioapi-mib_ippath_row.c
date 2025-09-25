typedef struct _MIB_IPPATH_ROW {
  SOCKADDR_INET Source;
  SOCKADDR_INET Destination;
  NET_LUID      InterfaceLuid;
  NET_IFINDEX   InterfaceIndex;
  SOCKADDR_INET CurrentNextHop;
  ULONG         PathMtu;
  ULONG         RttMean;
  ULONG         RttDeviation;
  union {
    ULONG LastReachable;
    ULONG LastUnreachable;
  };
  BOOLEAN       IsReachable;
  ULONG64       LinkTransmitSpeed;
  ULONG64       LinkReceiveSpeed;
} MIB_IPPATH_ROW, *PMIB_IPPATH_ROW;