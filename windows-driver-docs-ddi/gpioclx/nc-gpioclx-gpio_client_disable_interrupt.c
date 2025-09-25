GPIO_CLIENT_DISABLE_INTERRUPT GpioClientDisableInterrupt;

NTSTATUS GpioClientDisableInterrupt(
  [in] PVOID Context,
  [in] PGPIO_DISABLE_INTERRUPT_PARAMETERS DisableParameters
)
{...}