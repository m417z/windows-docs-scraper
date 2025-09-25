LSA_REGISTER_NOTIFICATION LsaRegisterNotification;

HANDLE LsaRegisterNotification(
  [in] SEC_THREAD_START StartFunction,
  [in] PVOID Parameter,
  [in] ULONG NotificationType,
  [in] ULONG NotificationClass,
  [in] ULONG NotificationFlags,
  [in] ULONG IntervalMinutes,
  [in] HANDLE WaitEvent
)
{...}