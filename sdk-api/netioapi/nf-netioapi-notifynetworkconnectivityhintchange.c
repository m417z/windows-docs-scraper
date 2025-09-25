IPHLPAPI_DLL_LINKAGE _NETIOAPI_SUCCESS_ NETIOAPI_API NotifyNetworkConnectivityHintChange(
  [in]  PNETWORK_CONNECTIVITY_HINT_CHANGE_CALLBACK Callback,
  [in]  PVOID                                      CallerContext,
  [in]  BOOLEAN                                    InitialNotification,
  [out] PHANDLE                                    NotificationHandle
);