NDIS_TCP_OFFLOAD_EVENT_INDICATE NdisTcpOffloadEventIndicate;

VOID NdisTcpOffloadEventIndicate(
  [in] IN NDIS_HANDLE NdisOffloadHandle,
  [in] IN ULONG EventType,
  [in] IN ULONG EventSpecificInformation
)
{...}