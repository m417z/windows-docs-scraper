VOID WIFI_DEVICE_CONFIG_INIT(
  WIFI_DEVICE_CONFIG                      *Config,
  ULONG                                   WdiVersion,
  PFN_WIFI_DEVICE_SEND_COMMAND            SendCommand,
  PFN_WIFI_DEVICE_CREATE_ADAPTER          CreateAdapter,
  PFN_WIFI_DEVICE_CREATE_WIFIDIRECTDEVICE CreateWifiDirectDevice
);