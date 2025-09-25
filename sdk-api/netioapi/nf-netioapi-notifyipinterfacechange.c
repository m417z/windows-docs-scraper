IPHLPAPI_DLL_LINKAGE _NETIOAPI_SUCCESS_ NETIOAPI_API NotifyIpInterfaceChange(
  [in]      ADDRESS_FAMILY               Family,
  [in]      PIPINTERFACE_CHANGE_CALLBACK Callback,
  [in]      PVOID                        CallerContext,
  [in]      BOOLEAN                      InitialNotification,
  [in, out] HANDLE                       *NotificationHandle
);