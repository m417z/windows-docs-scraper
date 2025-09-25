typedef struct _D3DKMT_QUERYSTATSTICS_PREPRATION {
  ULONG                          BroadcastStall;
  ULONG                          NbDMAPrepared;
  ULONG                          NbDMAPreparedLongPath;
  ULONG                          ImmediateHighestPreparationPass;
  D3DKMT_QUERYSTATISTICS_COUNTER AllocationsTrimmed;
} D3DKMT_QUERYSTATSTICS_PREPRATION;