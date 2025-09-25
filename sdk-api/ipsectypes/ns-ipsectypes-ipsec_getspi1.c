typedef struct IPSEC_GETSPI1_ {
  IPSEC_TRAFFIC1         inboundIpsecTraffic;
  FWP_IP_VERSION         ipVersion;
  union {
    IPSEC_V4_UDP_ENCAPSULATION0 *inboundUdpEncapsulation;
  };
  IPSEC_CRYPTO_MODULE_ID *rngCryptoModuleID;
} IPSEC_GETSPI1;