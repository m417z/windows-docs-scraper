typedef struct _NDIS_TCP_LARGE_SEND_OFFLOAD_NET_BUFFER_LIST_INFO {
  union {
    struct {
      ULONG Unused : 30;
      ULONG Type : 1;
      ULONG Reserved2 : 1;
    } Transmit;
    struct {
      ULONG MSS : 20;
      ULONG TcpHeaderOffset : 10;
      ULONG Type : 1;
      ULONG Reserved2 : 1;
    } LsoV1Transmit;
    struct {
      ULONG TcpPayload : 30;
      ULONG Type : 1;
      ULONG Reserved2 : 1;
    } LsoV1TransmitComplete;
    struct {
      ULONG MSS : 20;
      ULONG TcpHeaderOffset : 10;
      ULONG Type : 1;
      ULONG IPVersion : 1;
    } LsoV2Transmit;
    struct {
      ULONG Reserved : 30;
      ULONG Type : 1;
      ULONG Reserved2 : 1;
    } LsoV2TransmitComplete;
    PVOID Value;
  };
} NDIS_TCP_LARGE_SEND_OFFLOAD_NET_BUFFER_LIST_INFO, *PNDIS_TCP_LARGE_SEND_OFFLOAD_NET_BUFFER_LIST_INFO;