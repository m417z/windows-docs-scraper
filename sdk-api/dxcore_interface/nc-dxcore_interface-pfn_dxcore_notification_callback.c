PFN_DXCORE_NOTIFICATION_CALLBACK PfnDxcoreNotificationCallback;

void PfnDxcoreNotificationCallback(
       DXCoreNotificationType notificationType,
       IUnknown *object,
  [in] void *context
)
{...}