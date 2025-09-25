NDIS_TCP_OFFLOAD_FORWARD_COMPLETE NdisTcpOffloadForwardComplete;

VOID NdisTcpOffloadForwardComplete(
  [in] IN NDIS_HANDLE NdisMiniportHandle,
  [in] IN PNET_BUFFER_LIST NetBufferList
)
{...}