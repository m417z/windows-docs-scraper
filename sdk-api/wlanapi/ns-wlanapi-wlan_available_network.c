typedef struct _WLAN_AVAILABLE_NETWORK {
  WCHAR                  strProfileName[WLAN_MAX_NAME_LENGTH];
  DOT11_SSID             dot11Ssid;
  DOT11_BSS_TYPE         dot11BssType;
  ULONG                  uNumberOfBssids;
  BOOL                   bNetworkConnectable;
  WLAN_REASON_CODE       wlanNotConnectableReason;
  ULONG                  uNumberOfPhyTypes;
  DOT11_PHY_TYPE         dot11PhyTypes[WLAN_MAX_PHY_TYPE_NUMBER];
  BOOL                   bMorePhyTypes;
  WLAN_SIGNAL_QUALITY    wlanSignalQuality;
  BOOL                   bSecurityEnabled;
  DOT11_AUTH_ALGORITHM   dot11DefaultAuthAlgorithm;
  DOT11_CIPHER_ALGORITHM dot11DefaultCipherAlgorithm;
  DWORD                  dwFlags;
  DWORD                  dwReserved;
} WLAN_AVAILABLE_NETWORK, *PWLAN_AVAILABLE_NETWORK;