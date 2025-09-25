NDK_FN_GET_CONNECTION_DATA NdkFnGetConnectionData;

NTSTATUS NdkFnGetConnectionData(
  [in]            NDK_CONNECTOR *pNdkConnector,
  [out, optional] ULONG *pInboundReadLimit,
  [out, optional] ULONG *pOutboundReadLimit,
                  PVOID pPrivateData,
                  ULONG *pPrivateDataLength
)
{...}