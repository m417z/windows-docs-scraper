typedef struct _DOT11_VWIFI_COMBINATION_V3 {
  NDIS_OBJECT_HEADER Header;
  ULONG              uNumInfrastructure;
  ULONG              uNumAdhoc;
  ULONG              uNumSoftAP;
  ULONG              uNumVirtualStation;
  ULONG              uNumWFDGroup;
} DOT11_VWIFI_COMBINATION_V3, *PDOT11_VWIFI_COMBINATION_V3;