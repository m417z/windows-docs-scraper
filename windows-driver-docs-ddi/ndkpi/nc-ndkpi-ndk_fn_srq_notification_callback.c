NDK_FN_SRQ_NOTIFICATION_CALLBACK NdkFnSrqNotificationCallback;

VOID NdkFnSrqNotificationCallback(
  [in, optional] PVOID SrqNotificationContext,
  [in]           NTSTATUS SrqStatus
)
{...}