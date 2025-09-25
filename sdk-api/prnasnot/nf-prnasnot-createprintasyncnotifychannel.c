HRESULT CreatePrintAsyncNotifyChannel(
  [in]  PCWSTR                            pszName,
  [in]  PrintAsyncNotificationType        *pNotificationType,
  [in]  PrintAsyncNotifyUserFilter        eUserFilter,
  [in]  PrintAsyncNotifyConversationStyle eConversationStyle,
  [in]  IPrintAsyncNotifyCallback         *pCallback,
  [out] IPrintAsyncNotifyChannel          **ppIAsynchNotification
);