typedef struct _WLAN_BSS_LIST {
  DWORD          dwTotalSize;
  DWORD          dwNumberOfItems;
  WLAN_BSS_ENTRY wlanBssEntries[1];
} WLAN_BSS_LIST, *PWLAN_BSS_LIST;