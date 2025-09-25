MINIPORT_SEND_NET_BUFFER_LISTS MiniportSendNetBufferLists;

VOID MiniportSendNetBufferLists(
  [in] NDIS_HANDLE MiniportAdapterContext,
  [in] PNET_BUFFER_LIST NetBufferList,
  [in] NDIS_PORT_NUMBER PortNumber,
  [in] ULONG SendFlags
)
{...}