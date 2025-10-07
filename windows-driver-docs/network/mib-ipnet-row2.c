typedef struct _MIB_IPNET_ROW2 {
  SOCKADDR_INET     Address;
  NET_IFINDEX       InterfaceIndex;
  NET_LUID          InterfaceLuid;
  UCHAR             PhysicalAddress[IF_MAX_PHYS_ADDRESS_LENGTH];
  ULONG             PhysicalAddressLength;
  NL_NEIGHBOR_STATE State;
  union {
    struct {
      BOOLEAN IsRouter  :1;
      BOOLEAN IsUnreachable  :1;
    };
    UCHAR  Flags;
  };
  union {
    ULONG LastReachable;
    ULONG LastUnreachable;
  } ReachabilityTime;
} MIB_IPNET_ROW2, *PMIB_IPNET_ROW2;