typedef struct IPSEC_SA_DETAILS1_ {
  FWP_IP_VERSION                ipVersion;
  FWP_DIRECTION                 saDirection;
  IPSEC_TRAFFIC1                traffic;
  IPSEC_SA_BUNDLE1              saBundle;
  union {
    IPSEC_V4_UDP_ENCAPSULATION0 *udpEncapsulation;
  };
  FWPM_FILTER0                  *transportFilter;
  IPSEC_VIRTUAL_IF_TUNNEL_INFO0 virtualIfTunnelInfo;
} IPSEC_SA_DETAILS1;