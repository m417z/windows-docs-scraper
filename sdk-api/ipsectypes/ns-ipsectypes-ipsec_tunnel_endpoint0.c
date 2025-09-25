typedef struct IPSEC_TUNNEL_ENDPOINT0_ {
  FWP_IP_VERSION ipVersion;
  union {
    UINT32 v4Address;
    UINT8  v6Address[16];
  };
} IPSEC_TUNNEL_ENDPOINT0;