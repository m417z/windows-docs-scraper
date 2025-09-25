typedef struct _NDIS_TCP_LARGE_SEND_OFFLOAD_V1 {
  struct {
    ULONG Encapsulation;
    ULONG MaxOffLoadSize;
    ULONG MinSegmentCount;
    ULONG TcpOptions : 2;
    ULONG IpOptions : 2;
  } IPv4;
} NDIS_TCP_LARGE_SEND_OFFLOAD_V1, *PNDIS_TCP_LARGE_SEND_OFFLOAD_V1;