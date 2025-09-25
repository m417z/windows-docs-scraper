PUNREGISTER_NOTIFICATION_EVENT PunregisterNotificationEvent;

NTSTATUS PunregisterNotificationEvent(
  [in] PVOID _context,
  [in] HANDLE Handle,
  [in] PKEVENT NotificationEvent
)
{...}