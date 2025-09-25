AUTHZAPI BOOL AuthzRegisterCapChangeNotification(
  [out]          PAUTHZ_CAP_CHANGE_SUBSCRIPTION_HANDLE phCapChangeSubscription,
  [in]           LPTHREAD_START_ROUTINE                pfnCapChangeCallback,
  [in, optional] PVOID                                 pCallbackContext
);