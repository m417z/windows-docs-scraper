typedef struct IPSEC_AGGREGATE_SA_STATISTICS0_ {
  UINT32 activeSas;
  UINT32 pendingSaNegotiations;
  UINT32 totalSasAdded;
  UINT32 totalSasDeleted;
  UINT32 successfulRekeys;
  UINT32 activeTunnels;
  UINT32 offloadedSas;
} IPSEC_AGGREGATE_SA_STATISTICS0;