typedef struct _NDIS_LINK_STATE {
  NDIS_OBJECT_HEADER             Header;
  NDIS_MEDIA_CONNECT_STATE       MediaConnectState;
  NDIS_MEDIA_DUPLEX_STATE        MediaDuplexState;
  ULONG64                        XmitLinkSpeed;
  ULONG64                        RcvLinkSpeed;
  NDIS_SUPPORTED_PAUSE_FUNCTIONS PauseFunctions;
  ULONG                          AutoNegotiationFlags;
} NDIS_LINK_STATE, *PNDIS_LINK_STATE;