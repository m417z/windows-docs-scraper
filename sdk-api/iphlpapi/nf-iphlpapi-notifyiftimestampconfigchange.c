IPHLPAPI_DLL_LINKAGE DWORD NotifyIfTimestampConfigChange(
  [in, optional] PVOID                                       CallerContext,
  [in]           PINTERFACE_TIMESTAMP_CONFIG_CHANGE_CALLBACK Callback,
  [out]          HIFTIMESTAMPCHANGE                          *NotificationHandle
);