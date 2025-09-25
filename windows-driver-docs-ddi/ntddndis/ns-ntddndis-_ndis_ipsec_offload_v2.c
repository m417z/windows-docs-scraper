typedef struct _NDIS_IPSEC_OFFLOAD_V2 {
  ULONG   Encapsulation;
  BOOLEAN IPv6Supported;
  BOOLEAN IPv4Options;
  BOOLEAN IPv6NonIPsecExtensionHeaders;
  BOOLEAN Ah;
  BOOLEAN Esp;
  BOOLEAN AhEspCombined;
  BOOLEAN Transport;
  BOOLEAN Tunnel;
  BOOLEAN TransportTunnelCombined;
  BOOLEAN LsoSupported;
  BOOLEAN ExtendedSequenceNumbers;
  ULONG   UdpEsp;
  ULONG   AuthenticationAlgorithms;
  ULONG   EncryptionAlgorithms;
  ULONG   SaOffloadCapacity;
} NDIS_IPSEC_OFFLOAD_V2, *PNDIS_IPSEC_OFFLOAD_V2;