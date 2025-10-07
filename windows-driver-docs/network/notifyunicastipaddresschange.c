NETIOAPI_API NotifyUnicastIpAddressChange(
  _In_    ADDRESS_FAMILY                     Family,
  _In_    PUNICAST_IPADDRESS_CHANGE_CALLBACK Callback,
  _In_    PVOID                              CallerContext,
  _In_    BOOLEAN                            InitialNotification,
  _Inout_ HANDLE                             *NotificationHandle
);