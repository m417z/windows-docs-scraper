W_TCP_OFFLOAD_FORWARD_HANDLER WTcpOffloadForwardHandler;

NDIS_STATUS WTcpOffloadForwardHandler(
  [in] IN NDIS_HANDLE MiniportAdapterContext,
  [in] IN PVOID MiniportOffloadContext,
  [in] IN PNET_BUFFER_LIST NetBufferList
)
{...}