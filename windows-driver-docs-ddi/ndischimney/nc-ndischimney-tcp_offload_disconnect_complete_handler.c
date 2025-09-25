TCP_OFFLOAD_DISCONNECT_COMPLETE_HANDLER TcpOffloadDisconnectCompleteHandler;

VOID TcpOffloadDisconnectCompleteHandler(
  [in] IN NDIS_HANDLE ProtocolBindingContext,
  [in] IN PNET_BUFFER_LIST NetBufferList
)
{...}