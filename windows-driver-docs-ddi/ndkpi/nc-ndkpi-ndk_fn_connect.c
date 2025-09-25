NDK_FN_CONNECT NdkFnConnect;

NTSTATUS NdkFnConnect(
  [in]                                      NDK_CONNECTOR *pNdkConnector,
  [in]                                      NDK_QP *pNdkQp,
                                            const PSOCKADDR pSrcAddress,
  [in]                                      ULONG SrcAddressLength,
  [in]                                      const PSOCKADDR pDestAddress,
  [in]                                      ULONG DestAddressLength,
  [in]                                      ULONG InboundReadLimit,
  [in]                                      ULONG OutboundReadLimit,
  [_In_reads_bytes_opt_(PrivateDataLength)] const PVOID pPrivateData,
  [in]                                      ULONG PrivateDataLength,
  [in]                                      NDK_FN_REQUEST_COMPLETION RequestCompletion,
  [in, optional]                            PVOID RequestContext
)
{...}