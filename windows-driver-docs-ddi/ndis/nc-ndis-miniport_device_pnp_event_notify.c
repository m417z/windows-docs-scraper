MINIPORT_DEVICE_PNP_EVENT_NOTIFY MiniportDevicePnpEventNotify;

VOID MiniportDevicePnpEventNotify(
  [in] NDIS_HANDLE MiniportAdapterContext,
  [in] PNET_DEVICE_PNP_EVENT NetDevicePnPEvent
)
{...}