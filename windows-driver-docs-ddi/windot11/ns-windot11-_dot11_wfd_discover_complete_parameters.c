typedef struct _DOT11_WFD_DISCOVER_COMPLETE_PARAMETERS {
  NDIS_OBJECT_HEADER Header;
  NDIS_STATUS        Status;
  ULONG              uNumOfEntries;
  ULONG              uTotalNumOfEntries;
  ULONG              uListOffset;
  ULONG              uListLength;
} DOT11_WFD_DISCOVER_COMPLETE_PARAMETERS, *PDOT11_WFD_DISCOVER_COMPLETE_PARAMETERS;