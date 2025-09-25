typedef struct _NDIS_TCP_CONNECTION_OFFLOAD {
  NDIS_OBJECT_HEADER Header;
  ULONG              Encapsulation;
  ULONG              SupportIPv4 : 2;
  ULONG              SupportIPv6 : 2;
  ULONG              SupportIPv6ExtensionHeaders : 2;
  ULONG              SupportSack : 2;
  ULONG              CongestionAlgorithm : 4;
  ULONG              TcpConnectionOffloadCapacity;
  ULONG              Flags;
} NDIS_TCP_CONNECTION_OFFLOAD, *PNDIS_TCP_CONNECTION_OFFLOAD;