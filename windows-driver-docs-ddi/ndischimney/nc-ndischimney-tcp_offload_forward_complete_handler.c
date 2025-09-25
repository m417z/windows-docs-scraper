TCP_OFFLOAD_FORWARD_COMPLETE_HANDLER TcpOffloadForwardCompleteHandler;

VOID TcpOffloadForwardCompleteHandler(
  [in] IN NDIS_HANDLE ProtocolBindingContext,
  [in] IN PNET_BUFFER_LIST NetBufferList
)
{...}