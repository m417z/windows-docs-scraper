typedef struct _D3DKMT_QUERYSTATISTICS_PROCESS_INFORMATION {
  ULONG                                NodeCount;
  ULONG                                VidPnSourceCount;
  D3DKMT_QUERYSTATISTICS_SYSTEM_MEMORY SystemMemory;
  D3DKMT_ALIGN64 UINT64                Reserved[7];
} D3DKMT_QUERYSTATISTICS_PROCESS_INFORMATION;