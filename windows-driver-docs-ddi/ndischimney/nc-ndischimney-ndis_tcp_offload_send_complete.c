NDIS_TCP_OFFLOAD_SEND_COMPLETE NdisTcpOffloadSendComplete;

VOID NdisTcpOffloadSendComplete(
  [in] IN NDIS_HANDLE NdisMiniportHandle,
  [in] IN PNET_BUFFER_LIST NetBufferList
)
{...}