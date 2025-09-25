HRESULT UiaRaiseNotificationEvent(
  [in]           IRawElementProviderSimple *provider,
                 NotificationKind          notificationKind,
                 NotificationProcessing    notificationProcessing,
  [in, optional] BSTR                      displayString,
  [in]           BSTR                      activityId
);