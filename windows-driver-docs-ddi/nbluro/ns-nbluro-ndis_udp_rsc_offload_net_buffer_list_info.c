typedef struct _NDIS_UDP_RSC_OFFLOAD_NET_BUFFER_LIST_INFO {
  union {
    struct {
      USHORT SegCount;
      USHORT SegSize;
    } Receive;
    PVOID Value;
  };
} NDIS_UDP_RSC_OFFLOAD_NET_BUFFER_LIST_INFO, *PNDIS_UDP_RSC_OFFLOAD_NET_BUFFER_LIST_INFO;