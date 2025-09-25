typedef struct _WLAN_AVAILABLE_NETWORK_LIST {
  DWORD                  dwNumberOfItems;
  DWORD                  dwIndex;
#if ...
  WLAN_AVAILABLE_NETWORK *Network[];
#else
  WLAN_AVAILABLE_NETWORK Network[1];
#endif
} WLAN_AVAILABLE_NETWORK_LIST, *PWLAN_AVAILABLE_NETWORK_LIST;