typedef struct _NDIS_UDP_SEGMENTATION_OFFLOAD_NET_BUFFER_LIST_INFO {
  union {
    struct {
      ULONG MSS : 20;
      ULONG UdpHeaderOffset : 10;
      ULONG Reserved : 1;
      ULONG IPVersion : 1;
    } Transmit;
    PVOID Value;
  };
} NDIS_UDP_SEGMENTATION_OFFLOAD_NET_BUFFER_LIST_INFO, *PNDIS_UDP_SEGMENTATION_OFFLOAD_NET_BUFFER_LIST_INFO;