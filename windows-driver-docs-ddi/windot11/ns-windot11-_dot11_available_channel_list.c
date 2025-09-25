typedef struct _DOT11_AVAILABLE_CHANNEL_LIST {
  NDIS_OBJECT_HEADER Header;
  ULONG              uNumOfEntries;
  ULONG              uTotalNumOfEntries;
  ULONG              uChannelNumber[1];
} DOT11_AVAILABLE_CHANNEL_LIST, *PDOT11_AVAILABLE_CHANNEL_LIST;