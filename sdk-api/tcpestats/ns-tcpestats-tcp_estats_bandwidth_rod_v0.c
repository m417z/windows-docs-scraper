typedef struct _TCP_ESTATS_BANDWIDTH_ROD_v0 {
  ULONG64 OutboundBandwidth;
  ULONG64 InboundBandwidth;
  ULONG64 OutboundInstability;
  ULONG64 InboundInstability;
  BOOLEAN OutboundBandwidthPeaked;
  BOOLEAN InboundBandwidthPeaked;
} TCP_ESTATS_BANDWIDTH_ROD_v0, *PTCP_ESTATS_BANDWIDTH_ROD_v0;