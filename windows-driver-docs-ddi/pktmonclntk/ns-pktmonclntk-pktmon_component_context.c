typedef struct _PKTMON_COMPONENT_CONTEXT {
  LIST_ENTRY            ListLink;
  LIST_ENTRY            EdgeList;
  LONG                  EdgeCount;
  HANDLE                CompHandle;
  PKTMON_COMPONENT_TYPE CompType;
  PKTMON_PACKET_TYPE    PacketType;
  INT                   FlowEnabled : 1;
  INT                   DropEnabled : 1;
} PKTMON_COMPONENT_CONTEXT;