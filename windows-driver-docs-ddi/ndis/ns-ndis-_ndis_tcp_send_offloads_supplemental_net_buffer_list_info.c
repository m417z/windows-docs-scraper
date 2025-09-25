typedef struct _NDIS_TCP_SEND_OFFLOADS_SUPPLEMENTAL_NET_BUFFER_LIST_INFO {
  union {
    struct {
      ULONG IsEncapsulatedPacket : 1;
      ULONG EncapsulatedPacketOffsetsValid : 1;
      ULONG InnerFrameOffset : 8;
      ULONG TransportIpHeaderRelativeOffset : 6;
      ULONG TcpHeaderRelativeOffset : 10;
      ULONG IsInnerIPv6 : 1;
      ULONG TcpOptionsPresent : 1;
      ULONG Reserved : 4;
    } EncapsulatedPacketOffsets;
    PVOID Value;
  };
} NDIS_TCP_SEND_OFFLOADS_SUPPLEMENTAL_NET_BUFFER_LIST_INFO, *PNDIS_TCP_SEND_OFFLOADS_SUPPLEMENTAL_NET_BUFFER_LIST_INFO;