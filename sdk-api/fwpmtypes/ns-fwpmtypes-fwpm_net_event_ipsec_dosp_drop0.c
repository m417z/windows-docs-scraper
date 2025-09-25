typedef struct FWPM_NET_EVENT_IPSEC_DOSP_DROP0_ {
  FWP_IP_VERSION ipVersion;
  union {
    UINT32 publicHostV4Addr;
    UINT8  publicHostV6Addr[16];
  };
  union {
    UINT32 internalHostV4Addr;
    UINT8  internalHostV6Addr[16];
  };
  INT32          failureStatus;
  FWP_DIRECTION  direction;
} FWPM_NET_EVENT_IPSEC_DOSP_DROP0;