typedef struct _NDIS_TCP_IP_CHECKSUM_NET_BUFFER_LIST_INFO {
  union {
    struct {
      ULONG IsIPv4 : 1;
      ULONG IsIPv6 : 1;
      ULONG TcpChecksum : 1;
      ULONG UdpChecksum : 1;
      ULONG IpHeaderChecksum : 1;
      ULONG Reserved : 11;
      ULONG TcpHeaderOffset : 10;
    } Transmit;
    struct {
      ULONG TcpChecksumFailed : 1;
      ULONG UdpChecksumFailed : 1;
      ULONG IpChecksumFailed : 1;
      ULONG TcpChecksumSucceeded : 1;
      ULONG UdpChecksumSucceeded : 1;
      ULONG IpChecksumSucceeded : 1;
      ULONG Loopback : 1;
      ULONG TcpChecksumValueInvalid : 1;
      ULONG IpChecksumValueInvalid : 1;
    } Receive;
    PVOID Value;
  };
} NDIS_TCP_IP_CHECKSUM_NET_BUFFER_LIST_INFO, *PNDIS_TCP_IP_CHECKSUM_NET_BUFFER_LIST_INFO;