typedef struct _WLAN_INTERFACE_INFO_LIST {
  DWORD               dwNumberOfItems;
  DWORD               dwIndex;
#if ...
  WLAN_INTERFACE_INFO *InterfaceInfo[];
#else
  WLAN_INTERFACE_INFO InterfaceInfo[1];
#endif
} WLAN_INTERFACE_INFO_LIST, *PWLAN_INTERFACE_INFO_LIST;