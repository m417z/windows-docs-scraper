GPIO_CLIENT_UNMASK_INTERRUPT GpioClientUnmaskInterrupt;

NTSTATUS GpioClientUnmaskInterrupt(
  [in] PVOID Context,
  [in] PGPIO_ENABLE_INTERRUPT_PARAMETERS InterruptParameters
)
{...}