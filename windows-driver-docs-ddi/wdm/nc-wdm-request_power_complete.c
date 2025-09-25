REQUEST_POWER_COMPLETE RequestPowerComplete;

VOID RequestPowerComplete(
  [in]           PDEVICE_OBJECT DeviceObject,
  [in]           UCHAR MinorFunction,
  [in]           POWER_STATE PowerState,
  [in, optional] PVOID Context,
  [in]           PIO_STATUS_BLOCK IoStatus
)
{...}