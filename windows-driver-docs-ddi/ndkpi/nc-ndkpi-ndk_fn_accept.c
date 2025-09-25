NDK_FN_ACCEPT NdkFnAccept;

NTSTATUS NdkFnAccept(
  [in]                                      NDK_CONNECTOR *pNdkConnector,
  [in]                                      NDK_QP *pNdkQp,
  [in]                                      ULONG InboundReadLimit,
  [in]                                      ULONG OutboundReadLimit,
  [_In_reads_bytes_opt_(PrivateDataLength)] const PVOID pPrivateData,
  [in]                                      ULONG PrivateDataLength,
  [in, optional]                            NDK_FN_DISCONNECT_EVENT_CALLBACK DisconnectEvent,
  [in, optional]                            PVOID DisconnectEventContext,
  [in]                                      NDK_FN_REQUEST_COMPLETION RequestCompletion,
  [in, optional]                            PVOID RequestContext
)
{...}