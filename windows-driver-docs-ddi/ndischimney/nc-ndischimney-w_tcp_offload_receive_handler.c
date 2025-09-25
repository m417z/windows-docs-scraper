W_TCP_OFFLOAD_RECEIVE_HANDLER WTcpOffloadReceiveHandler;

NDIS_STATUS WTcpOffloadReceiveHandler(
  [in] IN NDIS_HANDLE MiniportAdapterContext,
  [in] IN PVOID MiniportOffloadContext,
  [in] IN PNET_BUFFER_LIST NetBufferList
)
{...}