typedef struct IPSEC_TUNNEL_ENDPOINTS2_ {
  FWP_IP_VERSION         ipVersion;
  union {
    UINT32 localV4Address;
    UINT8  localV6Address[16];
  };
  union {
    UINT32 remoteV4Address;
    UINT8  remoteV6Address[16];
  };
  UINT64                 localIfLuid;
  wchar_t                *remoteFqdn;
  UINT32                 numAddresses;
  IPSEC_TUNNEL_ENDPOINT0 *remoteAddresses;
} IPSEC_TUNNEL_ENDPOINTS2;