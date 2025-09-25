typedef struct FWPM_CONNECTION0_ {
  UINT64                 connectionId;
  FWP_IP_VERSION         ipVersion;
  union {
    UINT32 localV4Address;
    UINT8  localV6Address[16];
  };
  union {
    UINT32 remoteV4Address;
    UINT8  remoteV6Address[16];
  };
  GUID                   *providerKey;
  IPSEC_TRAFFIC_TYPE     ipsecTrafficModeType;
  IKEEXT_KEY_MODULE_TYPE keyModuleType;
  IKEEXT_PROPOSAL0       mmCrypto;
  IKEEXT_CREDENTIAL2     mmPeer;
  IKEEXT_CREDENTIAL2     emPeer;
  UINT64                 bytesTransferredIn;
  UINT64                 bytesTransferredOut;
  UINT64                 bytesTransferredTotal;
  FILETIME               startSysTime;
} FWPM_CONNECTION0;