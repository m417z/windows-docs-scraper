typedef struct _WIFI_PHY_INFO {
  WDI_PHY_TYPE        PhyType;
  SIZE_T              NumberDataRateEntries;
  WDI_DATA_RATE_ENTRY DataRateList[WDI_MAX_DATA_RATE_ENTRIES];
} WIFI_PHY_INFO;