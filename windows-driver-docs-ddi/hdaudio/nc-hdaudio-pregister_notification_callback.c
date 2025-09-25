PREGISTER_NOTIFICATION_CALLBACK PregisterNotificationCallback;

NTSTATUS PregisterNotificationCallback(
  PVOID _context,
  HANDLE Handle,
  PDEVICE_OBJECT Fdo,
  PHDAUDIO_DMA_NOTIFICATION_CALLBACK NotificationCallback,
  PVOID CallbackContext
)
{...}