typedef struct _DOT11_VWIFI_COMBINATION_V2 {
  NDIS_OBJECT_HEADER Header;
  ULONG              uNumInfrastructure;
  ULONG              uNumAdhoc;
  ULONG              uNumSoftAP;
  ULONG              uNumVirtualStation;
} DOT11_VWIFI_COMBINATION_V2, *PDOT11_VWIFI_COMBINATION_V2;