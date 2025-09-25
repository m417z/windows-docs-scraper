EVT_NET_DEVICE_PREVIEW_POWER_OFFLOAD EvtNetDevicePreviewPowerOffload;

NTSTATUS EvtNetDevicePreviewPowerOffload(
  [_In_] WDFDEVICE Device,
  [_In_] NETPOWEROFFLOAD PowerOffload
)
{...}