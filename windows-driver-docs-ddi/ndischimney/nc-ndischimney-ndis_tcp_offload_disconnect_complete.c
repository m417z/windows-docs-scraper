NDIS_TCP_OFFLOAD_DISCONNECT_COMPLETE NdisTcpOffloadDisconnectComplete;

VOID NdisTcpOffloadDisconnectComplete(
  [in] IN NDIS_HANDLE NdisMiniportHandle,
  [in] IN PNET_BUFFER_LIST NetBufferList
)
{...}