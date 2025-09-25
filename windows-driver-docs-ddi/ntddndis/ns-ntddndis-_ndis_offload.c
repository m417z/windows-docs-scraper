typedef struct _NDIS_OFFLOAD {
  NDIS_OBJECT_HEADER                       Header;
  NDIS_TCP_IP_CHECKSUM_OFFLOAD             Checksum;
  NDIS_TCP_LARGE_SEND_OFFLOAD_V1           LsoV1;
  NDIS_IPSEC_OFFLOAD_V1                    IPsecV1;
  NDIS_TCP_LARGE_SEND_OFFLOAD_V2           LsoV2;
  ULONG                                    Flags;
  NDIS_IPSEC_OFFLOAD_V2                    IPsecV2;
  NDIS_TCP_RECV_SEG_COALESCE_OFFLOAD       Rsc;
  NDIS_ENCAPSULATED_PACKET_TASK_OFFLOAD    EncapsulatedPacketTaskOffloadGre;
  NDIS_ENCAPSULATED_PACKET_TASK_OFFLOAD_V2 EncapsulatedPacketTaskOffloadVxlan;
  UCHAR                                    EncapsulationTypes;
  NDIS_RFC6877_464XLAT_OFFLOAD             Rfc6877Xlat;
  NDIS_UDP_SEGMENTATION_OFFLOAD            UdpSegmentation;
  NDIS_UDP_RSC_OFFLOAD                     UdpRsc;
} NDIS_OFFLOAD, *PNDIS_OFFLOAD;