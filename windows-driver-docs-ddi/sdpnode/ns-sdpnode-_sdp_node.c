typedef struct _SDP_NODE {
  SDP_NODE_HEADER hdr;
  ULONG           DataSize;
  SDP_NODE_DATA   u;
  PVOID           Reserved;
} SDP_NODE, *PSDP_NODE;