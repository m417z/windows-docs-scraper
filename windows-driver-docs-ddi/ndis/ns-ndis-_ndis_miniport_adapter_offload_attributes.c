typedef struct _NDIS_MINIPORT_ADAPTER_OFFLOAD_ATTRIBUTES {
  NDIS_OBJECT_HEADER           Header;
  PNDIS_OFFLOAD                DefaultOffloadConfiguration;
  PNDIS_OFFLOAD                HardwareOffloadCapabilities;
  PNDIS_TCP_CONNECTION_OFFLOAD DefaultTcpConnectionOffloadConfiguration;
  PNDIS_TCP_CONNECTION_OFFLOAD TcpConnectionOffloadHardwareCapabilities;
} NDIS_MINIPORT_ADAPTER_OFFLOAD_ATTRIBUTES, *PNDIS_MINIPORT_ADAPTER_OFFLOAD_ATTRIBUTES;