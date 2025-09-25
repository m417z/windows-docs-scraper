GPIO_CLIENT_QUERY_ACTIVE_INTERRUPTS GpioClientQueryActiveInterrupts;

NTSTATUS GpioClientQueryActiveInterrupts(
  [in]      PVOID Context,
  [in, out] PGPIO_QUERY_ACTIVE_INTERRUPTS_PARAMETERS QueryActiveParameters
)
{...}