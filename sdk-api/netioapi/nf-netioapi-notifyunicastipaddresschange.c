IPHLPAPI_DLL_LINKAGE _NETIOAPI_SUCCESS_ NETIOAPI_API NotifyUnicastIpAddressChange(
  [in]      ADDRESS_FAMILY                     Family,
  [in]      PUNICAST_IPADDRESS_CHANGE_CALLBACK Callback,
  [in]      PVOID                              CallerContext,
  [in]      BOOLEAN                            InitialNotification,
  [in, out] HANDLE                             *NotificationHandle
);