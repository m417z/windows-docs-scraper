GPIO_CLIENT_CLEAR_ACTIVE_INTERRUPTS GpioClientClearActiveInterrupts;

NTSTATUS GpioClientClearActiveInterrupts(
  [in]      PVOID Context,
  [in, out] PGPIO_CLEAR_ACTIVE_INTERRUPTS_PARAMETERS ClearParameters
)
{...}