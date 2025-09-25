typedef struct _DOT11_SUPPORTED_ANTENNA_LIST {
  ULONG                   uNumOfEntries;
  ULONG                   uTotalNumOfEntries;
  DOT11_SUPPORTED_ANTENNA dot11SupportedAntenna[1];
} DOT11_SUPPORTED_ANTENNA_LIST, *PDOT11_SUPPORTED_ANTENNA_LIST;