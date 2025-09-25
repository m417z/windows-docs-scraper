EVT_UDECX_WDF_DEVICE_QUERY_USB_CAPABILITY EvtUdecxWdfDeviceQueryUsbCapability;

NTSTATUS EvtUdecxWdfDeviceQueryUsbCapability(
  [in]            WDFDEVICE UdecxWdfDevice,
  [in]            PGUID CapabilityType,
  [in]            ULONG OutputBufferLength,
  [out, optional] PVOID OutputBuffer,
  [out]           PULONG ResultLength
)
{...}