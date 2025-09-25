PROTOCOL_RECEIVE_NET_BUFFER_LISTS ProtocolReceiveNetBufferLists;

VOID ProtocolReceiveNetBufferLists(
  [in] NDIS_HANDLE ProtocolBindingContext,
  [in] PNET_BUFFER_LIST NetBufferLists,
  [in] NDIS_PORT_NUMBER PortNumber,
  [in] ULONG NumberOfNetBufferLists,
  [in] ULONG ReceiveFlags
)
{...}