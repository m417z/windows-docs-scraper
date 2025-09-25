typedef struct _WLAN_DEVICE_SERVICE_GUID_LIST {
  DWORD dwNumberOfItems;
  DWORD dwIndex;
#if ...
  GUID  *DeviceService[];
#else
  GUID  DeviceService[1];
#endif
} WLAN_DEVICE_SERVICE_GUID_LIST, *PWLAN_DEVICE_SERVICE_GUID_LIST;