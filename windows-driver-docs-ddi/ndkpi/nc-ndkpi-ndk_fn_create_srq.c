NDK_FN_CREATE_SRQ NdkFnCreateSrq;

NTSTATUS NdkFnCreateSrq(
  [in]           NDK_PD *pNdkPd,
  [in]           ULONG SrqDepth,
  [in]           ULONG MaxReceiveRequestSge,
  [in]           ULONG NotifyThreshold,
  [in, optional] NDK_FN_SRQ_NOTIFICATION_CALLBACK SrqNotification,
  [in, optional] PVOID SrqNotificationContext,
  [in, optional] GROUP_AFFINITY *Affinity,
  [in]           NDK_FN_CREATE_COMPLETION CreateCompletion,
  [in, optional] PVOID RequestContext,
                 NDK_SRQ **ppNdkSrq
)
{...}