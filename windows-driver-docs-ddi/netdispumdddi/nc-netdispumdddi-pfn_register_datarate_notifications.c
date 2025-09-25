PFN_REGISTER_DATARATE_NOTIFICATIONS PfnRegisterDatarateNotifications;

NTSTATUS PfnRegisterDatarateNotifications(
  [in]           HANDLE hMiracastDeviceHandle,
  [in, optional] PVOID pNotificationContext,
  [in, optional] PFN_DATARATE_NOTIFICATION pfnDataRateNotify
)
{...}