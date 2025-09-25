NDIS_SWITCH_GET_NET_BUFFER_LIST_SWITCH_CONTEXT NdisSwitchGetNetBufferListSwitchContext;

PVOID NdisSwitchGetNetBufferListSwitchContext(
  [in] NDIS_SWITCH_CONTEXT NdisSwitchContext,
  [in] PNET_BUFFER_LIST NetBufferList,
  [in] PNDIS_SWITCH_NET_BUFFER_LIST_CONTEXT_TYPE ContextType
)
{...}