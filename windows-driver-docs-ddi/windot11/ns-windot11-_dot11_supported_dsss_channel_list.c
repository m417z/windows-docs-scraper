typedef struct _DOT11_SUPPORTED_DSSS_CHANNEL_LIST {
  ULONG                        uNumOfEntries;
  ULONG                        uTotalNumOfEntries;
  DOT11_SUPPORTED_DSSS_CHANNEL dot11SupportedDSSSChannel[1];
} DOT11_SUPPORTED_DSSS_CHANNEL_LIST, *PDOT11_SUPPORTED_DSSS_CHANNEL_LIST;