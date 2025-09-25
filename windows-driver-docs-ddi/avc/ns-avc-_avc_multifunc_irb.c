typedef struct _AVC_MULTIFUNC_IRB {
  AVC_IRB Common;
  union {
    AVC_PIN_COUNT          PinCount;
    AVC_PIN_DESCRIPTOR     PinDescriptor;
    AVC_PRECONNECT_INFO    PreConnectInfo;
    AVC_SETCONNECT_INFO    SetConnectInfo;
    AVC_PIN_ID             PinId;
    AVC_EXT_PLUG_COUNTS    ExtPlugCounts;
    AVC_UNIQUE_ID          UniqueID;
    AVC_PEER_DO_LOCATOR    PeerLocator;
    AVC_PEER_DO_LIST       PeerList;
    AVC_SUBUNIT_INFO_BLOCK Subunits;
  };
} AVC_MULTIFUNC_IRB, *PAVC_MULTIFUNC_IRB;