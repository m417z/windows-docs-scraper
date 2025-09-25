typedef struct _PKTMON_PACKET_CONTEXT_IN {
  PKTMON_HEADER Header;
  INT           Id;
  PVOID         Value;
  USHORT        Size;
} PKTMON_PACKET_CONTEXT_IN;