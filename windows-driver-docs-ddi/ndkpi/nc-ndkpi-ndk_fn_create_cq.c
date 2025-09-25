NDK_FN_CREATE_CQ NdkFnCreateCq;

NTSTATUS NdkFnCreateCq(
  [in]           NDK_ADAPTER *pNdkAdapter,
  [in]           ULONG CqDepth,
  [in]           NDK_FN_CQ_NOTIFICATION_CALLBACK CqNotification,
  [in, optional] PVOID CqNotificationContext,
  [in, optional] GROUP_AFFINITY *Affinity,
  [in]           NDK_FN_CREATE_COMPLETION CreateCompletion,
  [in, optional] PVOID RequestContext,
                 NDK_CQ **ppNdkCq
)
{...}