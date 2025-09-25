EVT_WIFI_DEVICE_CREATE_ADAPTER EvtWifiDeviceCreateAdapter;

NTSTATUS EvtWifiDeviceCreateAdapter(
  WDFDEVICE Device,
  NETADAPTER_INIT *AdapterInit
)
{...}