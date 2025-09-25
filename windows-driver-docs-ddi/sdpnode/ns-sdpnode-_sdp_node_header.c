typedef struct _SDP_NODE_HEADER {
  LIST_ENTRY Link;
  USHORT     Type;
  USHORT     SpecificType;
} SDP_NODE_HEADER, *PSDP_NODE_HEADER;