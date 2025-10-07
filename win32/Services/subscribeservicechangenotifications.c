DWORD WINAPI SubscribeServiceChangeNotifications(
  _In_     SC_HANDLE                     hService,
  _In_     SC_EVENT_TYPE                 eEventType,
  _In_     PSC_NOTIFICATION_CALLBACK     pCallback,
  _In_opt_ PVOID                         pCallbackContext,
  _Out_    PSC_NOTIFICATION_REGISTRATION *pSubscription
);