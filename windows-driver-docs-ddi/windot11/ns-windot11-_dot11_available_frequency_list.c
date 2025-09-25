typedef struct _DOT11_AVAILABLE_FREQUENCY_LIST {
  NDIS_OBJECT_HEADER Header;
  ULONG              uNumOfEntries;
  ULONG              uTotalNumOfEntries;
  ULONG              uFrequencyValue[1];
} DOT11_AVAILABLE_FREQUENCY_LIST, *PDOT11_AVAILABLE_FREQUENCY_LIST;