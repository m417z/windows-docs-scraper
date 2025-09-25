typedef struct FWPM_NET_EVENT_HEADER2_ {
  FILETIME       timeStamp;
  UINT32         flags;
  FWP_IP_VERSION ipVersion;
  UINT8          ipProtocol;
  union {
    UINT32           localAddrV4;
    FWP_BYTE_ARRAY16 localAddrV6;
  };
  union {
    UINT32           remoteAddrV4;
    FWP_BYTE_ARRAY16 remoteAddrV6;
  };
  UINT16         localPort;
  UINT16         remotePort;
  UINT32         scopeId;
  FWP_BYTE_BLOB  appId;
  SID            *userId;
  FWP_AF         addressFamily;
  SID            *packageSid;
} FWPM_NET_EVENT_HEADER2;