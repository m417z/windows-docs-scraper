NDK_FN_COMPLETE_CONNECT NdkFnCompleteConnect;

NTSTATUS NdkFnCompleteConnect(
  [in]           NDK_CONNECTOR *pNdkConnector,
  [in, optional] NDK_FN_DISCONNECT_EVENT_CALLBACK DisconnectEvent,
  [in, optional] PVOID DisconnectEventContext,
  [in]           NDK_FN_REQUEST_COMPLETION RequestCompletion,
  [in, optional] PVOID RequestContext
)
{...}