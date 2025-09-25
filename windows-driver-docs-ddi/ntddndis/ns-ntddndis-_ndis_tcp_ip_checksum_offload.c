typedef struct _NDIS_TCP_IP_CHECKSUM_OFFLOAD {
  struct {
    ULONG Encapsulation;
    ULONG IpOptionsSupported : 2;
    ULONG TcpOptionsSupported : 2;
    ULONG TcpChecksum : 2;
    ULONG UdpChecksum : 2;
    ULONG IpChecksum : 2;
  } IPv4Transmit;
  struct {
    ULONG Encapsulation;
    ULONG IpOptionsSupported : 2;
    ULONG TcpOptionsSupported : 2;
    ULONG TcpChecksum : 2;
    ULONG UdpChecksum : 2;
    ULONG IpChecksum : 2;
  } IPv4Receive;
  struct {
    ULONG Encapsulation;
    ULONG IpExtensionHeadersSupported : 2;
    ULONG TcpOptionsSupported : 2;
    ULONG TcpChecksum : 2;
    ULONG UdpChecksum : 2;
  } IPv6Transmit;
  struct {
    ULONG Encapsulation;
    ULONG IpExtensionHeadersSupported : 2;
    ULONG TcpOptionsSupported : 2;
    ULONG TcpChecksum : 2;
    ULONG UdpChecksum : 2;
  } IPv6Receive;
} NDIS_TCP_IP_CHECKSUM_OFFLOAD, *PNDIS_TCP_IP_CHECKSUM_OFFLOAD;