typedef struct DOT11_VWIFI_ATTRIBUTES {
  NDIS_OBJECT_HEADER      Header;
  ULONG                   uTotalNumOfEntries;
#if ...
  DOT11_VWIFI_COMBINATION *Combinations[];
#else
  DOT11_VWIFI_COMBINATION Combinations[1];
#endif
} DOT11_VWIFI_ATTRIBUTES, *PDOT11_VWIFI_ATTRIBUTES;