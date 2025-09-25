typedef struct DOT11_PHY_ID_LIST {
  NDIS_OBJECT_HEADER Header;
  ULONG              uNumOfEntries;
  ULONG              uTotalNumOfEntries;
  ULONG              dot11PhyId[1];
} DOT11_PHY_ID_LIST, *PDOT11_PHY_ID_LIST;