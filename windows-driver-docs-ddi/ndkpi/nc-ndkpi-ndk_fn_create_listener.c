NDK_FN_CREATE_LISTENER NdkFnCreateListener;

NTSTATUS NdkFnCreateListener(
  [in]           NDK_ADAPTER *pNdkAdapter,
  [in]           NDK_FN_CONNECT_EVENT_CALLBACK ConnectEvent,
  [in, optional] PVOID ConnectEventContext,
  [in]           NDK_FN_CREATE_COMPLETION CreateCompletion,
  [in, optional] PVOID RequestContext,
                 NDK_LISTENER **ppNdkListener
)
{...}