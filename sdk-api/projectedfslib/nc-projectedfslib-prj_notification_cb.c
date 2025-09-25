PRJ_NOTIFICATION_CB PrjNotificationCb;

HRESULT PrjNotificationCb(
  [in]           const PRJ_CALLBACK_DATA *callbackData,
  [in]           BOOLEAN isDirectory,
  [in]           PRJ_NOTIFICATION notification,
  [in, optional] PCWSTR destinationFileName,
  [in, out]      PRJ_NOTIFICATION_PARAMETERS *operationParameters
)
{...}