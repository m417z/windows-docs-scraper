typedef struct _PKTMON_EDGE_CONTEXT {
  LIST_ENTRY               ListLink;
  HANDLE                   EdgeHandle;
  PKTMON_COMPONENT_CONTEXT *CompContext;
  PKTMON_PACKET_TYPE       PacketType;
} PKTMON_EDGE_CONTEXT;