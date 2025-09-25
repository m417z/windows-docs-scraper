EVT_WIFI_DEVICE_CREATE_WIFIDIRECTDEVICE EvtWifiDeviceCreateWifidirectdevice;

NTSTATUS EvtWifiDeviceCreateWifidirectdevice(
  WDFDEVICE Device,
  WIFIDIRECT_DEVICE_INIT *WifiDirectDeviceInit
)
{...}