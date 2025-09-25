void NET_ADAPTER_LINK_STATE_INIT(
  [_Out_] NET_ADAPTER_LINK_STATE             *LinkState,
  [_In_]  ULONG64                            LinkSpeed,
  [_In_]  NET_IF_MEDIA_CONNECT_STATE         MediaConnectState,
  [_In_]  NET_IF_MEDIA_DUPLEX_STATE          MediaDuplexState,
  [_In_]  NET_ADAPTER_PAUSE_FUNCTION_TYPE    SupportedPauseFunctions,
  [_In_]  NET_ADAPTER_AUTO_NEGOTIATION_FLAGS AutoNegotiationFlags
);