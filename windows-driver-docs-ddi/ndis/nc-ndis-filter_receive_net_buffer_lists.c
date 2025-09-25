FILTER_RECEIVE_NET_BUFFER_LISTS FilterReceiveNetBufferLists;

VOID FilterReceiveNetBufferLists(
  [in] NDIS_HANDLE FilterModuleContext,
  [in] PNET_BUFFER_LIST NetBufferLists,
  [in] NDIS_PORT_NUMBER PortNumber,
  [in] ULONG NumberOfNetBufferLists,
  [in] ULONG ReceiveFlags
)
{...}