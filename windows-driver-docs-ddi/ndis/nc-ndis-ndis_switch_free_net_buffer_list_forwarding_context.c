NDIS_SWITCH_FREE_NET_BUFFER_LIST_FORWARDING_CONTEXT NdisSwitchFreeNetBufferListForwardingContext;

VOID NdisSwitchFreeNetBufferListForwardingContext(
  [in]      NDIS_SWITCH_CONTEXT NdisSwitchContext,
  [in, out] PNET_BUFFER_LIST NetBufferList
)
{...}