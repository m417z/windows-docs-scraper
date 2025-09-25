typedef struct IKEEXT_COMMON_STATISTICS1_ {
  IKEEXT_IP_VERSION_SPECIFIC_COMMON_STATISTICS1 v4Statistics;
  IKEEXT_IP_VERSION_SPECIFIC_COMMON_STATISTICS1 v6Statistics;
  UINT32                                        totalPacketsReceived;
  UINT32                                        totalInvalidPacketsReceived;
  UINT32                                        currentQueuedWorkitems;
} IKEEXT_COMMON_STATISTICS1;