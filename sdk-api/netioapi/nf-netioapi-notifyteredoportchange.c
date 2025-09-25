IPHLPAPI_DLL_LINKAGE _NETIOAPI_SUCCESS_ NETIOAPI_API NotifyTeredoPortChange(
  [in]      PTEREDO_PORT_CHANGE_CALLBACK Callback,
  [in]      PVOID                        CallerContext,
  [in]      BOOLEAN                      InitialNotification,
  [in, out] HANDLE                       *NotificationHandle
);