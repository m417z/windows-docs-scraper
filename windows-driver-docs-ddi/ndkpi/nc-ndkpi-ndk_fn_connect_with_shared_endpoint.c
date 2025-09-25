NDK_FN_CONNECT_WITH_SHARED_ENDPOINT NdkFnConnectWithSharedEndpoint;

NTSTATUS NdkFnConnectWithSharedEndpoint(
  [in]                                      NDK_CONNECTOR *pNdkConnector,
  [in]                                      NDK_QP *pNdkQp,
  [in]                                      NDK_SHARED_ENDPOINT *pNdkSharedEndpoint,
                                            const PSOCKADDR pDestAddress,
  [in]                                      ULONG DestAddressLength,
  [in]                                      ULONG InboundReadLimit,
  [in]                                      ULONG OutboundReadLimit,
  [_In_reads_bytes_opt_(PrivateDataLength)] const PVOID pPrivateData,
  [in]                                      ULONG PrivateDataLength,
  [in]                                      NDK_FN_REQUEST_COMPLETION RequestCompletion,
  [in, optional]                            PVOID RequestContext
)
{...}