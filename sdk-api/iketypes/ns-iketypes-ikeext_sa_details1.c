typedef struct IKEEXT_SA_DETAILS1_ {
  UINT64                 saId;
  IKEEXT_KEY_MODULE_TYPE keyModuleType;
  FWP_IP_VERSION         ipVersion;
  union {
    IPSEC_V4_UDP_ENCAPSULATION0 *v4UdpEncapsulation;
  };
  IKEEXT_TRAFFIC0        ikeTraffic;
  IKEEXT_PROPOSAL0       ikeProposal;
  IKEEXT_COOKIE_PAIR0    cookiePair;
  IKEEXT_CREDENTIALS1    ikeCredentials;
  GUID                   ikePolicyKey;
  UINT64                 virtualIfTunnelId;
  FWP_BYTE_BLOB          correlationKey;
} IKEEXT_SA_DETAILS1;