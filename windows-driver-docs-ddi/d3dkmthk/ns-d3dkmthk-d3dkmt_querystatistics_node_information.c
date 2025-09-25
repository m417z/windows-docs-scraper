typedef struct _D3DKMT_QUERYSTATISTICS_NODE_INFORMATION {
  D3DKMT_QUERYSTATISTICS_PROCESS_NODE_INFORMATION GlobalInformation;
  D3DKMT_QUERYSTATISTICS_PROCESS_NODE_INFORMATION SystemInformation;
  D3DKMT_NODE_PERFDATA                            NodePerfData;
#if ...
  UINT32                                          Reserved[3];
#else
  D3DKMT_ALIGN64 UINT64                           Reserved[8];
#endif
} D3DKMT_QUERYSTATISTICS_NODE_INFORMATION;