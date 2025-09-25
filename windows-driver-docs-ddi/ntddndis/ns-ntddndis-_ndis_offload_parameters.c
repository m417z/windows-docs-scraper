typedef struct _NDIS_OFFLOAD_PARAMETERS {
  NDIS_OBJECT_HEADER                 Header;
  UCHAR                              IPv4Checksum;
  UCHAR                              TCPIPv4Checksum;
  UCHAR                              UDPIPv4Checksum;
  UCHAR                              TCPIPv6Checksum;
  UCHAR                              UDPIPv6Checksum;
  UCHAR                              LsoV1;
  UCHAR                              IPsecV1;
  UCHAR                              LsoV2IPv4;
  UCHAR                              LsoV2IPv6;
  UCHAR                              TcpConnectionIPv4;
  UCHAR                              TcpConnectionIPv6;
  ULONG                              Flags;
  UCHAR                              IPsecV2;
  UCHAR                              IPsecV2IPv4;
  struct {
    UCHAR RscIPv4;
    UCHAR RscIPv6;
  };
  struct {
    UCHAR EncapsulatedPacketTaskOffload;
    UCHAR EncapsulationTypes;
  };
  union {
    struct {
      USHORT VxlanUDPPortNumber;
    } VxlanParameters;
    ULONG Value;
  } EncapsulationProtocolParameters;
  _ENCAPSULATION_PROTOCOL_PARAMETERS _ENCAPSULATION_PROTOCOL_PARAMETERS;
  struct {
    UCHAR IPv4;
    UCHAR IPv6;
  } UdpSegmentation;
  struct {
    UCHAR Enabled;
  } UdpRsc;
} NDIS_OFFLOAD_PARAMETERS, *PNDIS_OFFLOAD_PARAMETERS;