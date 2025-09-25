NDIS_TCP_OFFLOAD_RECEIVE_COMPLETE NdisTcpOffloadReceiveComplete;

VOID NdisTcpOffloadReceiveComplete(
  [in] IN NDIS_HANDLE NdisMiniportHandle,
  [in] IN PNET_BUFFER_LIST NetBufferList
)
{...}