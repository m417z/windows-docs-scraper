PUNREGISTER_NOTIFICATION_CALLBACK PunregisterNotificationCallback;

NTSTATUS PunregisterNotificationCallback(
  PVOID _context,
  HANDLE Handle,
  PHDAUDIO_DMA_NOTIFICATION_CALLBACK NotificationCallback,
  PVOID CallbackContext
)
{...}