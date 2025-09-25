GPIO_CLIENT_RECONFIGURE_INTERRUPT GpioClientReconfigureInterrupt;

NTSTATUS GpioClientReconfigureInterrupt(
  [in] PVOID Context,
  [in] PGPIO_RECONFIGURE_INTERRUPTS_PARAMETERS ReconfigureParameters
)
{...}