typedef struct _WLAN_COUNTRY_OR_REGION_STRING_LIST {
  DWORD                          dwNumberOfItems;
#if ...
  DOT11_COUNTRY_OR_REGION_STRING *pCountryOrRegionStringList[];
#else
  DOT11_COUNTRY_OR_REGION_STRING pCountryOrRegionStringList[1];
#endif
} WLAN_COUNTRY_OR_REGION_STRING_LIST, *PWLAN_COUNTRY_OR_REGION_STRING_LIST;