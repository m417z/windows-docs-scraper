NETIOAPI_API NotifyTeredoPortChange(
  _In_    PTEREDO_PORT_CHANGE_CALLBACK Callback,
  _In_    PVOID                        CallerContext,
  _In_    BOOLEAN                      InitialNotification,
  _Inout_ HANDLE *                     NotificationHandle
);