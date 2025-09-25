EVT_MBB_DEVICE_CREATE_ADAPTER EvtMbbDeviceCreateAdapter;

NTSTATUS EvtMbbDeviceCreateAdapter(
  WDFDEVICE Device,
  NETADAPTER_INIT *AdapterInit
)
{...}