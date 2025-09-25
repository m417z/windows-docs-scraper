PREGISTER_NOTIFICATION_EVENT PregisterNotificationEvent;

NTSTATUS PregisterNotificationEvent(
  [in] PVOID _context,
  [in] HANDLE Handle,
  [in] PKEVENT NotificationEvent
)
{...}