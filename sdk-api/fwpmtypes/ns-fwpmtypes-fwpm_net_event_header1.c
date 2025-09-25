typedef struct FWPM_NET_EVENT_HEADER1_ {
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
  union {
    struct {
      FWP_AF reserved1;
      union {
        struct {
          FWP_BYTE_ARRAY6 reserved2;
          FWP_BYTE_ARRAY6 reserved3;
          UINT32          reserved4;
          UINT32          reserved5;
          UINT16          reserved6;
          UINT32          reserved7;
          UINT32          reserved8;
          UINT16          reserved9;
          UINT64          reserved10;
        };
      };
    };
  };
} FWPM_NET_EVENT_HEADER1;