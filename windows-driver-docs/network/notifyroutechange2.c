NETIOAPI_API NotifyRouteChange2(
  _In_    ADDRESS_FAMILY             Family,
  _In_    PIPFORWARD_CHANGE_CALLBACK Callback,
  _In_    PVOID                      CallerContext,
  _In_    BOOLEAN                    InitialNotification,
  _Inout_ HANDLE                     *NotificationHandle
);