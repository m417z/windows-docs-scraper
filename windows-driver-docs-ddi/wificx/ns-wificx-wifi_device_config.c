typedef struct _WIFI_DEVICE_CONFIG {
  ULONG                                   Size;
  ULONG                                   WdiVersion;
  PFN_WIFI_DEVICE_SEND_COMMAND            SendCommand;
  PFN_WIFI_DEVICE_CREATE_ADAPTER          CreateAdapter;
  PFN_WIFI_DEVICE_CREATE_WIFIDIRECTDEVICE CreateWifiDirectDevice;
} WIFI_DEVICE_CONFIG;