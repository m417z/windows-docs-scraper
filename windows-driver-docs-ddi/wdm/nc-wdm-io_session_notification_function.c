IO_SESSION_NOTIFICATION_FUNCTION IoSessionNotificationFunction;

NTSTATUS IoSessionNotificationFunction(
  [in] PVOID SessionObject,
  [in] PVOID IoObject,
  [in] ULONG Event,
  [in] PVOID Context,
  [in] PVOID NotificationPayload,
  [in] ULONG PayloadLength
)
{...}