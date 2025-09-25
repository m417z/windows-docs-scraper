typedef struct FWPS_PACKET_LIST_INBOUND_IPSEC_INFORMATION0_ {
  unsigned isSecure : 1;
  unsigned isTransportMode : 1;
  unsigned isTunnelMode : 1;
  unsigned isTransportModeVerified : 1;
  unsigned isTunnelModeVerified : 1;
  unsigned isDeTunneled : 1;
} FWPS_PACKET_LIST_INBOUND_IPSEC_INFORMATION0;