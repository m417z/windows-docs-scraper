typedef struct IPSEC_SA_DETAILS0_ {
  FWP_IP_VERSION   ipVersion;
  FWP_DIRECTION    saDirection;
  IPSEC_TRAFFIC0   traffic;
  IPSEC_SA_BUNDLE0 saBundle;
  union {
    IPSEC_V4_UDP_ENCAPSULATION0 *udpEncapsulation;
  };
  FWPM_FILTER0     *transportFilter;
} IPSEC_SA_DETAILS0;