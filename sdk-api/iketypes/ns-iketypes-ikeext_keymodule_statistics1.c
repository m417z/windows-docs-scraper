typedef struct IKEEXT_KEYMODULE_STATISTICS1_ {
  IKEEXT_IP_VERSION_SPECIFIC_KEYMODULE_STATISTICS1 v4Statistics;
  IKEEXT_IP_VERSION_SPECIFIC_KEYMODULE_STATISTICS1 v6Statistics;
  UINT32                                           errorFrequencyTable[97];
  UINT32                                           mainModeNegotiationTime;
  UINT32                                           quickModeNegotiationTime;
  UINT32                                           extendedModeNegotiationTime;
} IKEEXT_KEYMODULE_STATISTICS1;