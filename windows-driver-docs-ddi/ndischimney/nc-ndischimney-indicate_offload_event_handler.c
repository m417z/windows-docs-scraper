INDICATE_OFFLOAD_EVENT_HANDLER IndicateOffloadEventHandler;

VOID IndicateOffloadEventHandler(
  [in] IN NDIS_HANDLE ProtocolBindingContext,
  [in] IN PNDIS_PROTOCOL_OFFLOAD_BLOCK_LIST OffloadBlockList,
  [in] IN ULONG IndicationCode
)
{...}