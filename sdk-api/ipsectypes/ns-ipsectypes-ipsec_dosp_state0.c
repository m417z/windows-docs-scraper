typedef struct IPSEC_DOSP_STATE0_ {
  UINT8  publicHostV6Addr[16];
  UINT8  internalHostV6Addr[16];
  UINT64 totalInboundIPv6IPsecAuthPackets;
  UINT64 totalOutboundIPv6IPsecAuthPackets;
  UINT32 durationSecs;
} IPSEC_DOSP_STATE0;