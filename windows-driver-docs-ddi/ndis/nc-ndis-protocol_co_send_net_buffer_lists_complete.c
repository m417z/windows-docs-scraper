PROTOCOL_CO_SEND_NET_BUFFER_LISTS_COMPLETE ProtocolCoSendNetBufferListsComplete;

VOID ProtocolCoSendNetBufferListsComplete(
  [in] NDIS_HANDLE ProtocolVcContext,
  [in] PNET_BUFFER_LIST NetBufferLists,
  [in] ULONG SendCompleteFlags
)
{...}