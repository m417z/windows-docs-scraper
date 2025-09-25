typedef struct {
  IP4_ADDRESS IpAddress;
  UCHAR       chProtocol;
  BYTE        BitMask[1];
} DNS_WKS_DATA, *PDNS_WKS_DATA;