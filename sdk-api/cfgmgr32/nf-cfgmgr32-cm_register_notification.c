CMAPI CONFIGRET CM_Register_Notification(
  [in]           PCM_NOTIFY_FILTER   pFilter,
  [in, optional] PVOID               pContext,
  [in]           PCM_NOTIFY_CALLBACK pCallback,
  [out]          PHCMNOTIFICATION    pNotifyContext
);