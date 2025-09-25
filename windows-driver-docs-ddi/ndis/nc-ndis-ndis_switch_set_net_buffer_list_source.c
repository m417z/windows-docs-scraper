NDIS_SWITCH_SET_NET_BUFFER_LIST_SOURCE NdisSwitchSetNetBufferListSource;

NDIS_STATUS NdisSwitchSetNetBufferListSource(
  [in] NDIS_SWITCH_CONTEXT NdisSwitchContext,
       PNET_BUFFER_LIST NetBufferList,
  [in] NDIS_SWITCH_PORT_ID PortId,
  [in] NDIS_SWITCH_NIC_INDEX NicIndex
)
{...}