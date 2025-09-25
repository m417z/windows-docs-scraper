NDK_FN_DISCONNECT NdkFnDisconnect;

NTSTATUS NdkFnDisconnect(
  [in]           NDK_CONNECTOR *pNdkConnector,
  [in]           NDK_FN_REQUEST_COMPLETION RequestCompletion,
  [in, optional] PVOID RequestContext
)
{...}