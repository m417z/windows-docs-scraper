PROTOCOL_SEND_NET_BUFFER_LISTS_COMPLETE ProtocolSendNetBufferListsComplete;

VOID ProtocolSendNetBufferListsComplete(
  [in] NDIS_HANDLE ProtocolBindingContext,
  [in] PNET_BUFFER_LIST NetBufferList,
  [in] ULONG SendCompleteFlags
)
{...}