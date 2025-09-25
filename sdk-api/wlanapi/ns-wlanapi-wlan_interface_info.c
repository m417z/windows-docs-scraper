typedef struct _WLAN_INTERFACE_INFO {
  GUID                 InterfaceGuid;
  WCHAR                strInterfaceDescription[WLAN_MAX_NAME_LENGTH];
  WLAN_INTERFACE_STATE isState;
} WLAN_INTERFACE_INFO, *PWLAN_INTERFACE_INFO;