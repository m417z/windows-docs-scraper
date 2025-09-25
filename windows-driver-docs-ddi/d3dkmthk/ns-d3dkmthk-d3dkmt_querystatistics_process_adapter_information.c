typedef struct _D3DKMT_QUERYSTATISTICS_PROCESS_ADAPTER_INFORMATION {
  ULONG                                                NbSegments;
  ULONG                                                NodeCount;
  ULONG                                                VidPnSourceCount;
  ULONG                                                VirtualMemoryUsage;
  D3DKMT_QUERYSTATISTICS_DMA_BUFFER                    DmaBuffer;
  D3DKMT_QUERYSTATISTICS_COMMITMENT_DATA               CommitmentData;
  D3DKMT_QUERYSTATISTICS_POLICY                        _Policy;
  D3DKMT_QUERYSTATISTICS_PROCESS_INTERFERENCE_COUNTERS ProcessInterferenceCounters;
  D3DKMT_ALIGN64 UINT64                                Reserved[9];
  D3DKMT_CLIENTHINT                                    ClientHint;
  UINT                                                 Reserve;
} D3DKMT_QUERYSTATISTICS_PROCESS_ADAPTER_INFORMATION;