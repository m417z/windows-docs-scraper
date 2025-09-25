IPHLPAPI_DLL_LINKAGE _NETIOAPI_SUCCESS_ NETIOAPI_API NotifyRouteChange2(
  [in]      ADDRESS_FAMILY             AddressFamily,
  [in]      PIPFORWARD_CHANGE_CALLBACK Callback,
  [in]      PVOID                      CallerContext,
  [in]      BOOLEAN                    InitialNotification,
  [in, out] HANDLE                     *NotificationHandle
);