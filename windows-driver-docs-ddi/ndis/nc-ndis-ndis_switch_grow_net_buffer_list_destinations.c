NDIS_SWITCH_GROW_NET_BUFFER_LIST_DESTINATIONS NdisSwitchGrowNetBufferListDestinations;

NDIS_STATUS NdisSwitchGrowNetBufferListDestinations(
  [in]  NDIS_SWITCH_CONTEXT NdisSwitchContext,
        PNET_BUFFER_LIST NetBufferList,
  [in]  UINT32 NumberOfNewDestinations,
  [out] PNDIS_SWITCH_FORWARDING_DESTINATION_ARRAY *Destinations
)
{...}