NDIS_SWITCH_ADD_NET_BUFFER_LIST_DESTINATION NdisSwitchAddNetBufferListDestination;

NDIS_STATUS NdisSwitchAddNetBufferListDestination(
  [in]      NDIS_SWITCH_CONTEXT NdisSwitchContext,
  [in, out] PNET_BUFFER_LIST NetBufferList,
  [in]      PNDIS_SWITCH_PORT_DESTINATION Destination
)
{...}