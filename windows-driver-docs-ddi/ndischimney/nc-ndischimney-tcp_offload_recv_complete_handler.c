TCP_OFFLOAD_RECV_COMPLETE_HANDLER TcpOffloadRecvCompleteHandler;

VOID TcpOffloadRecvCompleteHandler(
  [in] IN NDIS_HANDLE ProtocolBindingContext,
  [in] IN PNET_BUFFER_LIST NetBufferList
)
{...}