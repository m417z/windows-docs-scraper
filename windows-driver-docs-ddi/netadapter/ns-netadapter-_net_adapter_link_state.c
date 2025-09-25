typedef struct _NET_ADAPTER_LINK_STATE {
  ULONG                              Size;
  ULONG64                            TxLinkSpeed;
  ULONG64                            RxLinkSpeed;
  NET_IF_MEDIA_CONNECT_STATE         MediaConnectState;
  NET_IF_MEDIA_DUPLEX_STATE          MediaDuplexState;
  NET_ADAPTER_PAUSE_FUNCTION_TYPE    SupportedPauseFunctions;
  NET_ADAPTER_AUTO_NEGOTIATION_FLAGS AutoNegotiationFlags;
} NET_ADAPTER_LINK_STATE;