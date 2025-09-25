NDK_FN_CQ_NOTIFICATION_CALLBACK NdkFnCqNotificationCallback;

VOID NdkFnCqNotificationCallback(
  [in, optional] PVOID CqNotificationContext,
  [in]           NTSTATUS CqStatus
)
{...}