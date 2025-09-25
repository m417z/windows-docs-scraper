typedef struct IPSEC_TUNNEL_ENDPOINTS0_ {
  FWP_IP_VERSION ipVersion;
  union {
    UINT32 localV4Address;
    UINT8  localV6Address[16];
  };
  union {
    UINT32 remoteV4Address;
    UINT8  remoteV6Address[16];
  };
} IPSEC_TUNNEL_ENDPOINTS0;