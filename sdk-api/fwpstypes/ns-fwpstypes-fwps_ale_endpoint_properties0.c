typedef struct FWPS_ALE_ENDPOINT_PROPERTIES0_ {
  UINT64         endpointId;
  FWP_IP_VERSION ipVersion;
  union {
    UINT32 localV4Address;
    UINT8  localV6Address[16];
  };
  union {
    UINT32 remoteV4Address;
    UINT8  remoteV6Address[16];
  };
  UINT8          ipProtocol;
  UINT16         localPort;
  UINT16         remotePort;
  UINT64         localTokenModifiedId;
  UINT64         mmSaId;
  UINT64         qmSaId;
  UINT32         ipsecStatus;
  UINT32         flags;
  FWP_BYTE_BLOB  appId;
} FWPS_ALE_ENDPOINT_PROPERTIES0;