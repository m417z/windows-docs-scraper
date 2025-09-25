GPIO_CLIENT_START_CONTROLLER GpioClientStartController;

NTSTATUS GpioClientStartController(
  [in] PVOID Context,
  [in] BOOLEAN RestoreContext,
  [in] WDF_POWER_DEVICE_STATE PreviousPowerState
)
{...}