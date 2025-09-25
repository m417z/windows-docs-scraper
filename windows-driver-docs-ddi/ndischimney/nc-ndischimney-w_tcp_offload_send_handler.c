W_TCP_OFFLOAD_SEND_HANDLER WTcpOffloadSendHandler;

NDIS_STATUS WTcpOffloadSendHandler(
  [in] IN NDIS_HANDLE MiniportAdapterContext,
  [in] IN PVOID MiniportOffloadContext,
  [in] IN PNET_BUFFER_LIST NetBufferList
)
{...}