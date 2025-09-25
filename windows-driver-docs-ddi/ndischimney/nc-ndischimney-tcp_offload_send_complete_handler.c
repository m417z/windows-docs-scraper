TCP_OFFLOAD_SEND_COMPLETE_HANDLER TcpOffloadSendCompleteHandler;

VOID TcpOffloadSendCompleteHandler(
  [in] IN NDIS_HANDLE ProtocolBindingContext,
  [in] IN PNET_BUFFER_LIST NetBufferList
)
{...}