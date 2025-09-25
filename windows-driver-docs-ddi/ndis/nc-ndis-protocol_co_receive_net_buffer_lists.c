PROTOCOL_CO_RECEIVE_NET_BUFFER_LISTS ProtocolCoReceiveNetBufferLists;

VOID ProtocolCoReceiveNetBufferLists(
  [in] NDIS_HANDLE ProtocolBindingContext,
  [in] NDIS_HANDLE ProtocolVcContext,
  [in] PNET_BUFFER_LIST NetBufferLists,
  [in] ULONG NumberOfNetBufferLists,
  [in] ULONG ReceiveFlags
)
{...}