HRESULT RouterCreatePrintAsyncNotificationChannel(
  [in] PCWSTR                            pName,
  [in] PrintAsyncNotificationType        *pNotificationType,
       PrintAsyncNotifyUserFilter        eNotifyFilter,
  [in] PrintAsyncNotifyConversationStyle eConversationStyle,
  [in] IPrintAsyncNotifyCallback         *pCallback,
       IPrintAsyncNotifyChannel          **ppIAsynchNotification
);