NDIS_SWITCH_UPDATE_NET_BUFFER_LIST_DESTINATIONS NdisSwitchUpdateNetBufferListDestinations;

NDIS_STATUS NdisSwitchUpdateNetBufferListDestinations(
  [in]      NDIS_SWITCH_CONTEXT NdisSwitchContext,
  [in, out] PNET_BUFFER_LIST NetBufferList,
  [in]      UINT32 NumberOfNewDestinations,
  [in]      PNDIS_SWITCH_FORWARDING_DESTINATION_ARRAY Destinations
)
{...}