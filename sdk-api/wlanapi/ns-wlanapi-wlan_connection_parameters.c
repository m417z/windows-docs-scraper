typedef struct _WLAN_CONNECTION_PARAMETERS {
  WLAN_CONNECTION_MODE wlanConnectionMode;
#if ...
  LPCWSTR              strProfile;
#else
  LPCWSTR              strProfile;
#endif
  PDOT11_SSID          pDot11Ssid;
  PDOT11_BSSID_LIST    pDesiredBssidList;
  DOT11_BSS_TYPE       dot11BssType;
  DWORD                dwFlags;
} WLAN_CONNECTION_PARAMETERS, *PWLAN_CONNECTION_PARAMETERS;