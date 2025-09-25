NDIS_SWITCH_SET_NET_BUFFER_LIST_SWITCH_CONTEXT NdisSwitchSetNetBufferListSwitchContext;

NDIS_STATUS NdisSwitchSetNetBufferListSwitchContext(
  [in]      NDIS_SWITCH_CONTEXT NdisSwitchContext,
  [in, out] PNET_BUFFER_LIST NetBufferList,
  [in]      PNDIS_SWITCH_NET_BUFFER_LIST_CONTEXT_TYPE ContextType,
  [in]      PVOID Context
)
{...}