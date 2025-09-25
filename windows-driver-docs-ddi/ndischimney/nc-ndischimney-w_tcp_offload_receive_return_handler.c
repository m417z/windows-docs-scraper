W_TCP_OFFLOAD_RECEIVE_RETURN_HANDLER WTcpOffloadReceiveReturnHandler;

NDIS_STATUS WTcpOffloadReceiveReturnHandler(
  [in] IN NDIS_HANDLE MiniportAdapterContext,
  [in] IN PNET_BUFFER_LIST NetBufferList
)
{...}