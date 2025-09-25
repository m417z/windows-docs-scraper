typedef union _NET_IPV6_ADDRESS {
  struct {
    UINT64 NetworkPrefix;
    UINT64 InterfaceIdentifier;
  } Unicast;
  UINT8  Value[16];
} NET_IPV6_ADDRESS;