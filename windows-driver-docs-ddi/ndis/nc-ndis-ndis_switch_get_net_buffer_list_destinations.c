NDIS_SWITCH_GET_NET_BUFFER_LIST_DESTINATIONS NdisSwitchGetNetBufferListDestinations;

VOID NdisSwitchGetNetBufferListDestinations(
  [in]      NDIS_SWITCH_CONTEXT NdisSwitchContext,
  [in, out] PNET_BUFFER_LIST NetBufferList,
  [out]     PNDIS_SWITCH_FORWARDING_DESTINATION_ARRAY *Destinations
)
{...}