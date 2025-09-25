GPIO_CLIENT_STOP_CONTROLLER GpioClientStopController;

NTSTATUS GpioClientStopController(
  [in] PVOID Context,
  [in] BOOLEAN SaveContext,
  [in] WDF_POWER_DEVICE_STATE TargetState
)
{...}