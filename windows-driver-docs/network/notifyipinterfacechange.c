NETIOAPI_API NotifyIpInterfaceChange(
  _In_    ADDRESS_FAMILY               Family,
  _In_    PIPINTERFACE_CHANGE_CALLBACK Callback,
  _In_    PVOID                        CallerContext,
  _In_    BOOLEAN                      InitialNotification,
  _Inout_ HANDLE                       *NotificationHandle
);