NDK_FN_CREATE_CONNECTOR NdkFnCreateConnector;

NTSTATUS NdkFnCreateConnector(
  [in]           NDK_ADAPTER *pNdkAdapter,
  [in]           NDK_FN_CREATE_COMPLETION CreateCompletion,
  [in, optional] PVOID RequestContext,
                 NDK_CONNECTOR **ppNdkConnector
)
{...}