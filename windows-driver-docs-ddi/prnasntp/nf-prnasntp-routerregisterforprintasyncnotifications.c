HRESULT RouterRegisterForPrintAsyncNotifications(
  [in]  PCWSTR                            pName,
  [in]  PrintAsyncNotificationType        *pNotificationType,
  [in]  PrintAsyncNotifyUserFilter        eNotifyFilter,
  [in]  PrintAsyncNotifyConversationStyle eConversationStyle,
  [in]  IPrintAsyncNotifyCallback         *pCallback,
  [out] HANDLE                            *phNotify
);