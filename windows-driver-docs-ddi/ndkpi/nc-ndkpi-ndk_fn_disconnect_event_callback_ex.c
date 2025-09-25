NDK_FN_DISCONNECT_EVENT_CALLBACK_EX NdkFnDisconnectEventCallbackEx;

VOID NdkFnDisconnectEventCallbackEx(
  [in, optional] PVOID DisconnectEventContext,
  [in]           ULONG ProviderDisconnectReason
)
{...}